void minus_loop_2() {
    int x = -20 ;
    int rm = 5; 
    /*@
    loop invariant -20 <= x <= 0;
    loop invariant 0 <= rm <= 5;
    loop invariant x + 4*rm == 0;
    loop assigns x, rm;
    loop variant -x;
    */
    while (x < 0){
        x += 4 ;
        rm -- ; 
    }
    // @ assert x == 0 && rm == 0;
}