/*@
requires n > 0;
*/
void foo(int n) {
    int x = 1;
    int y = 0;
    /*@
    loop invariant x >= 1;
    loop invariant x + y == n;
    loop invariant 0 <= y;
    loop invariant x - 1 == \at(x - 1, PreLoop) + (x - \at(x, PreLoop));
    loop invariant \forall integer k; x <= k <= n ==> y == n - x;
    loop invariant y == n - x;
    loop invariant x == \at(x, PreLoop) + (x - \at(x, PreLoop));
    loop invariant x <= n +1;
    loop invariant x < n +1;
    loop invariant x - 1 <= n;
    loop invariant x + y == n;
    loop invariant 0 <= y;
    loop invariant 0 <= y || x <= n +1;
    loop invariant 0 <= x - 1;
    loop invariant 0 < y;
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