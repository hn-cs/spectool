#include <stdlib.h>
/*@
requires 0 <= n <= 126;
assigns \nothing;
*/
int sum(char n) {
    int s = 0;
    char k = 0;
    /*@
    loop invariant n >= 0 ==> k <= n + 1;
    loop assigns s;
    loop assigns k;
    */
    while(k <= n) {    
        s = s + (int)k;
        k = k + 1;
    }
    //@ assert s == (int)((n+1)*(n)/2);
    return (int)s;
}
int main() {
    int s = sum(5);
    //@ assert s == 15;
}