void minus_loop_2() {
    int x = -20 ;
    int rm = 5; 
    /*@
    loop invariant x <= 0;
    loop invariant x + 4 * rm == 0;
    loop invariant x % 4 == 0;
    loop invariant rm == -x / 4;
    loop invariant rm <= 5;
    loop invariant 0 <= rm;
    loop invariant -20 <= x;
    loop assigns x;
    loop assigns rm;
    */
    while (x < 0){
        x += 4 ;
        rm -- ; 
    }
    // @ assert x == 0 && rm == 0;
}