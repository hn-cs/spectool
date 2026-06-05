#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include "assert.h"
int main() {
    int lo, mid, hi;
    lo = 0;
    mid = unknown();
    if (!(mid > 0 && mid < INT_MAX)) return 0;
    hi = 2*mid;
    /*@
    loop invariant lo + hi == 2 * \at(mid, Pre);
    loop invariant hi - lo == 2 * mid;
    loop invariant 0 <= mid <= \at(mid, Pre);
    loop invariant lo <= \at(mid, Pre);
    loop invariant hi >= \at(mid, Pre);
    loop invariant mid;
    loop invariant mid <= \at(mid, Pre);
    loop invariant lo + mid == \at(mid, Pre);
    loop invariant lo + hi == 2 * \at(mid, Pre);
    loop invariant hi - mid == \at(mid, Pre);
    loop invariant hi - lo == 2 * mid;
    loop invariant 0 <= mid;
    loop assigns mid;
    loop assigns lo;
    loop assigns hi;
    */
    while (mid > 0) {
        lo = lo + 1;
        hi = hi - 1;
        mid = mid - 1;
    }
    // @ assert(lo == hi);
    return 0;
}
