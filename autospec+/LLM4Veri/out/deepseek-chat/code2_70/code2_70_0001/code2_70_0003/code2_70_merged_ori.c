/*@
requires n > 0;
*/
void foo(int n) {
    int x = 1;
    int y = 0;
    /*@
    loop invariant y == n - x;
    loop invariant x <= n +1;
    loop invariant x < n +1;
    loop invariant 0 <= y;
    loop invariant 0 <= y || x <= n +1;
    loop invariant 0 < y;
    loop invariant x == \at(x, PreLoop) + (x - \at(x, PreLoop));
    loop invariant x - 1 <= n;
    loop invariant x + y == n;
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