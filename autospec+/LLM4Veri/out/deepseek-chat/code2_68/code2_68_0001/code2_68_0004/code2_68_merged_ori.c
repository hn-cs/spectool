/*@
requires n > 0;
*/
void foo(int n) {
    int y = 0;
    int x = 1;
    /*@
    loop invariant x == \old(x) +1 ==> y == \old(y) -1;
    loop invariant x + y == n;
    loop invariant y == n - (x - 1);
    loop invariant y <= n;
    loop invariant y <= n - 1;
    loop invariant y <= n - 1 || 1 <= x;
    loop invariant y < n - 1;
    loop invariant x == \old(x) + 1 ==> y == n - \old(x);
    loop invariant x == 1 || y == n - x + 1;
    loop invariant x <= n;
    loop invariant x <= n+1;
    loop invariant x <= n || y <= n - 1;
    loop invariant x <= n || 1 <= x;
    loop invariant x < n;
    loop invariant x + y == n - 1;
    loop invariant n - x < y;
    loop invariant 1 <= x;
    loop invariant 1 < x;
    loop invariant 1 < x;
    loop invariant 1 < x;
    loop invariant 1 < x;
    loop invariant 1 < x;
    loop invariant 1 < x;
    loop invariant 1 < x;
    loop invariant 1 < x;
    loop invariant 1 < x;
    loop invariant 1 < x;
    loop invariant 0 <= y;
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