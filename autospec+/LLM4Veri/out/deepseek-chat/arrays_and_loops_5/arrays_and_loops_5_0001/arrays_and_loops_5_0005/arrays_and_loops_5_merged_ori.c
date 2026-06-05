int fun(int x, int y , int *r) {
    *r = x;
    int d = 0;
    /*@
    loop invariant x % y == *r % y;
    loop invariant d == (x - *r) / y;
    loop invariant 0 <= y;
    loop invariant 0 <= *r;
    loop invariant 0 < y;
    loop invariant 0 < y || 0 <= *r;
    loop invariant 0 < *r;
    loop invariant x == *r + d * y;
    loop invariant 0 <= d;
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