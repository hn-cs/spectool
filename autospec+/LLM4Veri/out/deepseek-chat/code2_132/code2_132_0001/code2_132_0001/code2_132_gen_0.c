void foo(int j, int c, int t) {
    int i = 0;
    /*@
    loop invariant 0 <= i;
    loop invariant j == 0 || j == 2*i;
    loop invariant t == 0 || t == c - 48;
    loop assigns i, j, t;
    */
    while(unknown()) {
        if(c > 48) {
            if (c < 57) {
                j = i + i;
                t = c - 48;
                i = j + t;
            }
        }
    } 
    // @ assert i >= 0;
}