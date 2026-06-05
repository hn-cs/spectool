#include <limits.h>
/*@
requires INT_MIN <= b - a <= INT_MAX;
requires INT_MIN <= a - b <= INT_MAX;
ensures \result >= 0;
ensures \result == (a >= b ? a - b : b - a);
*/
int distance(int a, int b) {
    if (a < b) return b - a; 
    else return a - b; 
}
int main(){
    int a = -10;
    int b = 10;
    int result = distance(a, b);
    //@ assert result == 20;
    return 0;
}