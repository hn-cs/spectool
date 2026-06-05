int main(){
    int i=0;

    /*@
    loop invariant i <= 30;
    loop invariant 30 - i;
    loop invariant 0 <= i;
    loop assigns i;
    */
    while (i<30){
        ++i;
    }
    //@assert i==30;
   
}