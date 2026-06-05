#include <stdlib.h>

/*@
requires 0 <= n <= 65535;
assigns \nothing;
*/
int sum(int n) {
    int s = 0;
    int k = 0;

    /*@
    loop invariant s == k * (k - 1) / 2;
    loop invariant 0 <= k;
    loop assigns s;
    loop assigns k;
    */
    while(k <= n) {    
        s = s + k;
        k = k + 1;
    }
    return s;
}

int main() {
    int s = sum(5);
    //@ assert s == 15;
}