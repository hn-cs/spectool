void minus_loop() {
    int x = 0 ;
    /*@
    loop invariant x <= 0;
    loop invariant x - (-10);
    loop invariant -10 <= x;
    loop assigns x;
    */
    while (x > -10){
        -- x ;
    }
    // @ assert x == -10 ;
}