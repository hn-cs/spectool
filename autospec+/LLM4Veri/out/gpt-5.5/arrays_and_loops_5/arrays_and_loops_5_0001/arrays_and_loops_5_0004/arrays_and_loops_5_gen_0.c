/*@
requires \valid(r);
requires x >= 0;
requires y > 0;
assigns *r;
ensures x == \result * y + *r;
ensures 0 <= *r < y;
ensures \result >= 0;
*/
int fun(int x, int y , int *r) {
    *r = x;
    int d = 0;
    /*@
    loop invariant y == \at(y,Pre);
    loop invariant x == \at(x,Pre);
    loop invariant r == \at(r,Pre);
    loop invariant d > 0 ==> *r == x - d * y;
    loop invariant d == 0 ==> *r == x;
    loop invariant 0 <= d;
    loop invariant *r + d * y == x;
    loop assigns d;
    loop assigns *r;
    */
    while (*r >= y) {
        *r = *r - y;
        d = d + 1;
    }
    return d;
}
int main() {
    int a = 3;
    int num = fun(1, 2, &a);
    // @ assert a == 1;
    // @ assert num == 0;
    return 0;
}