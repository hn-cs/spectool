#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include<stdlib.h>
#include "assert.h"
int main() {
    int n = unknown();
    if (!(0 <= n && n <= 1000)) return 0;
    int *x = malloc(n * sizeof(int));
    /*@
    loop invariant i > 0 ==> x[0] == 0;
    loop invariant i == 0 || x[i-1] == 0;
    loop invariant i <= 1000;
    loop invariant i <= 1000 || 0 <= n - i;
    loop invariant i < n ==> i < 1000;
    loop invariant \forall integer k; 0 <= k < i ==> x[k] == 0 * i;
    loop invariant \forall integer k; 0 < k < i ==> x[k] == x[k-1];
    loop invariant 0 <= n - i;
    loop invariant n == 0 ==> i == 0;
    loop invariant n <= 1000;
    loop invariant i > 0 ==> x[i-1] == 0;
    loop invariant i == n ==> \forall integer k; 0 <= k < n ==> x[k] == 0;
    loop invariant i <= n;
    loop invariant \forall integer k; 0 <= k < n && k < i ==> x[k] == 0;
    loop invariant \forall integer k; 0 <= k < i ==> x[k] == 0;
    loop invariant 0 <= n;
    loop invariant 0 <= i;
    loop assigns x[0..n-1];
    loop assigns i;
    */
    for (int i = 0; i < n; i++) x[i] = 0;
    for (int i = 0; i < n; i++) //@ assert(x[i] == 0);
    return 0;
}
