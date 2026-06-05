# ACSL 翻译 few-shot 参考

> 抽取自 AutoSpec+ `LLM4Veri/src/prompt/`（contract 与 loop invariant 示例）。`spec-acsl` 在把自然语言 Pre/Post 翻成 ACSL 时参考这些成对样例。**只展示 ACSL，不解释。**

## ACSL 速记
- 前/后置条件：`requires` / `ensures`
- 帧条件（可被修改的内存）：`assigns`（无副作用写 `assigns \nothing;`）
- 返回值：`\result`
- 循环：`loop invariant`（每次迭代开始/结束都成立）、`loop assigns`（循环修改的变量集合）、`loop variant`（非负且严格递减的整型表达式，用于停机）
- 内存有效性：`\valid(p+(0..n-1))`；量词：`\forall integer k; 0<=k<n ==> ...`、`\exists integer k; ...`

---

## 示例 1：函数契约（带 behavior）

```c
/* @ >>> INFILL <<< */
int abs(int val) {
    if(val < 0) return -val;
    return val;
}
```
ACSL：
```
requires INT_MIN < val <= INT_MAX;
ensures \result >= 0;
behavior positive:
    assumes val >= 0;
    ensures \result == val;
behavior negative:
    assumes val < 0;
    ensures \result == -val;
assigns \nothing;
```

## 示例 2：查找类函数契约（量词 + 蕴含）

```c
int foo(uint32_t *map, uint32_t *key, uint32_t len) { ... 找到相等项返回0，否则-1 ... }
```
ACSL：
```
requires \valid((uint32_t *)(map+(0..len-1)));
requires \valid((uint32_t *)(key+(0..len-1)));
requires len <= SIZE;
ensures \result == -1 ==> \forall integer i; 0 <= i < len ==> map[i] != key[i];
ensures \result == 0 ==> \exists integer i; 0 <= i < len && map[i] == key[i];
assigns \nothing;
```

## 示例 3：循环不变式 + loop assigns（多变量）

```c
for(int i=0; i<n; i++){ p[i]=0; x=t1+t2; y=t1+t2; a--; b--; }
```
ACSL：
```
loop invariant 0 <= i <= n;
loop invariant x == y;
loop invariant x >= 1;
loop invariant a - b == q - w;
loop invariant \forall integer j; 0 <= j < i ==> ((char*)p)[j] == 0;
loop assigns ((char*)p)[0..n-1];
loop assigns i;
loop assigns a, b, x, y;
```

## 示例 4：带 break 的查找循环不变式

```c
for (int i = 0; i < len; i++){ if (map[i]==key[i]){ ret=0; break; } x=x+y; y=y+1; }
```
ACSL：
```
loop invariant 0 <= i <= len;
loop invariant ret == -1 || ret == 0;
loop invariant ret == -1 ==> \forall integer j; 0 <= j < i ==> map[j] != key[j];
loop invariant ret == 0 ==> (\exists integer j; 0 <= j < i && map[j] == key[j]);
loop assigns i, x, y, ret;
```

---

## 翻译要点（从 NL 到 ACSL 的常见对应）
| 自然语言 Post | ACSL |
|---|---|
| "数组前 i 项已被清零" | `\forall integer j; 0<=j<i ==> a[j]==0` |
| "返回值非负" | `ensures \result >= 0;` |
| "找到则返回索引，否则 -1" | 用 `\result>=0 ==> ...` 与 `\result==-1 ==> \forall...` 两条 ensures |
| "不修改任何内存" | `assigns \nothing;` |
| "只修改数组 a 的 [0,n)" | `assigns a[0..n-1];` |
| "循环计数器范围" | `loop invariant 0<=i<=n;` |
| "循环会停机" | `loop variant n - i;` |

## 常见失败 → 修法（供 spec-repair 参考）
- **缺 `loop assigns`** → WP 证不出循环外变量不变；为循环体所有被写变量补 `loop assigns`。
- **`ensures` 太强** → 实现给不出该后条件；按 `serves:` 检查是否真被调用者需要，必要时弱化。
- **`requires` 太弱** → 函数内出现越界/溢出 goal 证不动；补 `\valid(...)` / 范围约束。
- **`assigns` 漏项** → Assigns goal 失败；把遗漏的左值加入 assigns。
