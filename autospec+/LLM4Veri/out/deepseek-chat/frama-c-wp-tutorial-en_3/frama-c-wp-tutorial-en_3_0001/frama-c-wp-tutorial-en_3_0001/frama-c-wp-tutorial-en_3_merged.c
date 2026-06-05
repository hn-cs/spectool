#include<limits.h>
/*@
requires \valid(a);
ensures \result == *a + 5;
assigns \nothing;
*/
int plus_5(int* a) {
    return *a + 5;
}
int main(){
    int a = 10;
    int b = plus_5(&a);
    //@ assert b == 15;    
}