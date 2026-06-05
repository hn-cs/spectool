#include<limits.h>
/*@
    logic integer ax_b(integer a, integer x, integer b) = a * x + b;
*/
/*@
requires -((INT_MAX-4)/3) <= x <= (INT_MAX-4)/3;
ensures \result == ax_b(3,x,4);
assigns \nothing;
*/
int restricted(int x){
    return 3*x + 4;
}
int main(){
    int x = 10;
    int result = restricted(x);
    //@ assert result == 34;
    return 0;
}