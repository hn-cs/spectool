int main(){
    int i=0;
    /*@
    loop invariant i == \at(i, Pre) + \at(i, Here) - \at(i, Pre);
    loop invariant i == 30 - (30 - i);
    loop invariant i <= 30;
    loop invariant 30 - i;
    loop invariant 30 - i == 30 - i;
    loop invariant 0 <= i;
    loop invariant 0 <= 30 - i;
    loop assigns i;
    */
    while (i<30){
        ++i;
    }
    //@assert i==30;
}