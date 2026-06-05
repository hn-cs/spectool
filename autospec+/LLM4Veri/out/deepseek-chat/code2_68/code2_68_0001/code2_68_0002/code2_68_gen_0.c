/*@
requires n > 0;
*/
void foo(int n) {
    int y = 0;
    int x = 1;
    /*@
    loop invariant y == n - (x - 1);
    loop invariant x == \old(x) + 1 ==> y == n - \old(x);
    loop invariant n - x < y <= n;
    loop invariant y >= 0;
    loop invariant x <= n+1;
    loop invariant 0 <= x;
    loop assigns y;
    loop assigns x;
    */
    while (x <= n) {
        y = n - x;
        x = x +1;
    }
    if (n > 0) {
        // @ assert y <= n;
    }
}