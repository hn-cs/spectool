// hhk2008_true-unreach-call.c
int main() {
    int a;
    int b;
    
    int res, cnt;

    res = a;
    cnt = b;
    
    /*@
    loop invariant res > a ==> cnt >= 0;
    loop invariant res == a || cnt >= 0;
    loop invariant res != a ==> cnt < b;
    loop invariant cnt >= b ==> res == a;
    loop invariant cnt == 0 ==> res == a + b;
    loop invariant cnt != b ==> res > a;
    loop invariant b > 0 ==> a <= res <= a + b;
    loop invariant b > 0 ==> 0 <= cnt <= b;
    loop invariant b == cnt ==> a == res;
    loop invariant b <= 0 ==> res == a && cnt == b;
    loop invariant res > a ==> cnt < b;
    loop invariant res == a ==> cnt == b;
    loop invariant res == a + b - cnt;
    loop invariant res == a + (b - cnt);
    loop invariant res - a == b - cnt;
    loop invariant res + cnt == a + b;
    loop invariant cnt > 0 ==> res < a + b;
    loop invariant cnt == b ==> res == a;
    loop invariant cnt == a + b - res;
    loop invariant cnt <= b;
    loop invariant cnt < b || res == a;
    loop invariant cnt < b ==> res > a;
    loop invariant cnt < 0 ==> res == a && cnt == b;
    loop invariant a <= res;
    loop invariant (res + cnt) % 2 == (a + b) % 2;
    loop assigns res;
    loop assigns cnt;
    */
    while (cnt > 0) {
    	cnt = cnt - 1;
        res = res + 1;
    }

    // @ assert(res == a + b);
    
    return 0;
}
