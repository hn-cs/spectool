int fun(int x, int y) {
    int r = x;
    int d = 0;

    /*@
    loop invariant r + d * y == x;
    loop invariant d >= 0;
    loop assigns r, d;
    */
    while (r >= y) {
        // Beginning
        r = r - y;
        d = d + 1;
        // ENd
        // @ assert r + d*y == x;
    }
    return d;
}