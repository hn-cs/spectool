/*@
    requires x == 1 && y == 2;
    requires *r == 3;
*/
int fun(int x, int y , int *r) {
    *r = x;
    int d = 0;

    /*@
    loop invariant 0 <= *r <= x;
    loop invariant x == *r + d * y;
    loop invariant d >= 0;
    loop invariant y > 0;
    loop assigns *r, d;
    */
    while (*r >= y) {
        *r = *r - y;
        d = d + 1;
    }
    // @ assert *r == 1;
    // @ assert d == 0;
}