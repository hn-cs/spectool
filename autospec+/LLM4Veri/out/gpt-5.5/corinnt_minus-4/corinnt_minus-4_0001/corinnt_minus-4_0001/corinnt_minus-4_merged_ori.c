void minus_loop_2() {
    int x = -20 ;
    int rm = 5; 
    /*@
    loop invariant x == 4 * rm - 20;
    loop invariant x <= 0;
    loop invariant rm;
    loop invariant 0 <= rm;
    loop assigns x;
    loop assigns rm;
    */
    while (x < 0){
        x += 4 ;
        rm -- ; 
    }
    // @ assert x == 0 && rm == 0;
}