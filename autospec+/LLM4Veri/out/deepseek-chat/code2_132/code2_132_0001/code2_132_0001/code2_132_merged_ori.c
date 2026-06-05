void foo(int j, int c, int t) {
    int i = 0;
    /*@
    loop invariant t == 0 || t == c - 48;
    loop invariant j == 0 || j == 2*i;
    loop invariant 0 <= i;
    loop assigns t;
    loop assigns j;
    loop assigns i;
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