/*@
    requires x == 1 && y == 2;
    requires *r == 3;
*/
int fun(int x, int y , int *r) {
    *r = x;
    int d = 0;

    /*@
    loop invariant x == *r + d * y;
    loop invariant 0 <= d;
    loop invariant 0 <= *r;
    loop invariant 0 < y;
    loop invariant *r <= x;
    loop assigns d;
    loop assigns *r;
    */
    while (*r >= y) {
        *r = *r - y;
        d = d + 1;
    }
    // @ assert *r == 1;
    // @ assert d == 0;
}