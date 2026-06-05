int fun(int x, int y , int *r) {
    *r = x;
    int d = 0;
    /*@
    loop invariant y == \at(y,Pre);
    loop invariant x == \at(x,Pre);
    loop invariant r == \at(r,Pre);
    loop invariant d > 0 ==> *r == x - d * y;
    loop invariant d == 0 ==> *r == x;
    loop invariant \valid(r);
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