#include <stdlib.h>

/*@
requires n <= 65535;
assigns \nothing;
ensures n < 0 ==> \result == 0;
ensures n >= 0 ==> \result == n * (n + 1) / 2;
ensures \result >= 0;
*/
int sum(int n) {
    int s = 0;
    int k = 0;

    /*@
    loop invariant s == k * (k - 1) / 2;
    loop invariant k > 0 ==> s >= k - 1;
    loop invariant k == 0 ==> s == 0;
    loop invariant 2 * s == k * (k - 1);
    loop invariant 0 <= s;
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
    // @ assert s == 15;
}