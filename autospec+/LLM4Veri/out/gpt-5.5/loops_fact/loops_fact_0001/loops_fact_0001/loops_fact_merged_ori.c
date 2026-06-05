#include <stdio.h>
/*@
  axiomatic Factorial {
  logic integer fact(integer n);
  axiom case_n:
    \forall integer n;
    n >= 1 ==> fact(n) == n*fact(n-1);
  axiom case_0:
    fact(0) == 1;
  }
*/
int factorial(int n) {
  int i = 1;
  int f = 1;
  /*@
  loop invariant n - i + 1;
  loop invariant i == 1 || i <= n + 1;
  loop invariant f == fact(i - 1);
  loop invariant 1 <= i;
  loop assigns i;
  loop assigns f;
  */
  while (i <= n)  {
    f = f * i;
    i = i + 1;
  }
  return f;
}
void main() {
  int t = factorial(5);
  // @ assert t == 120;
}