int fun(int x, int y , int *r) {
    *r = x;
    int d = 0;
    /*@
    loop invariant *r + d * y == x;
    loop invariant d >= 0;
    loop assigns *r, d;
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