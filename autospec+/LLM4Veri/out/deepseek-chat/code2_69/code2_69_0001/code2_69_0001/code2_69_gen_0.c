/*@
requires n > 0;
*/
void foo(int n) {
    int x = 1;
    int y = 0;
    /*@
    loop invariant 0 <= x <= n+1;
    loop invariant y == n - x + 1;
    loop invariant y >= 0;
    loop assigns x, y;
    */
    while (x <= n) {
        y = n - x;
        x = x +1;
    }
    if (n > 0) {
      // @ assert y >= 0;
    }
}