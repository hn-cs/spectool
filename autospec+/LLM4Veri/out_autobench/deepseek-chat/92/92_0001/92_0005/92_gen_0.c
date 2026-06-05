int main(){

    int x = 0;
    int y = 0;

    /*@
    loop invariant y >= 0;
    loop invariant x == 0;
    loop invariant \at(x, Pre) == x;
    loop invariant y == \at(y, Pre) + x * (\at(y, Pre) - y);
    loop invariant y == 0;
    loop invariant y == 0 || y < 0;
    loop invariant x == \at(x, Pre);
    loop invariant x == 0;
    loop invariant \at(x, Pre) == x;
    loop invariant 0 <= y;
    loop assigns y;
    */
    while(y >= 0){
        y = y + x;
    }

    //post-condition
    // @ assert( y >= 0);
}
