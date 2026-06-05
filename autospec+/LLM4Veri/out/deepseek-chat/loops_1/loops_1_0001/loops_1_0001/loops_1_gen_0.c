int main(){
    int i=0;
    /*@
    loop invariant 0 <= i <= 30;
    loop invariant i == \at(i, Pre) + \at(i, Here) - \at(i, Pre);
    loop assigns i;
    loop variant 30 - i;
    */
    while (i<30){
        ++i;
    }
    //@assert i==30;
}