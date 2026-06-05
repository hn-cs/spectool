#include <limits.h>
/*@
requires a >= b ==> a - b <= INT_MAX;
requires a < b ==> b - a <= INT_MAX;
ensures a >= b ==> \result == a - b;
ensures a < b ==> \result == b - a;
ensures \result >= 0;
assigns \nothing;
*/
int distance(int a, int b) {
    if (a < b) return b - a; 
    else return a - b; 
}
int main(){
    int a = -10;
    int b = 10;
    int result = distance(a, b);
    // @ assert result == 20;
    return 0;
}