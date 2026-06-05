/*@
requires n > 0;
*/
void foo(int n) {
    int x = 1;
    int y = 0;
    /*@
    loop invariant y == n - (x - 1);
    loop invariant x - 1 <= n;
    loop invariant n - x;
    loop invariant 0 <= x - 1;
    loop assigns y;
    loop assigns x;
    */
    while (x <= n) {
        y = n - x;
        x = x +1;
    }
    if (n > 0) {
      // @ assert y < n;
    }
}