#include<limits.h>
/*@
requires \valid_read(a);
requires *a <= INT_MAX - 5;
requires *a >= INT_MIN + 5;
ensures \result == *a + 5;
assigns \nothing;
*/
int plus_5(int* a) {
    return *a + 5;
}
int main(){
    int a = 10;
    int b = plus_5(&a);
    // @ assert b == 15;    
}