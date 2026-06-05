#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include "assert.h"
int main() {
    unsigned int i,j,a,b;
    int flag = unknown();
    a = 0;
    b = 0;
    j = 1;
    if (flag) {
        i = 0;
    } else {
        i = 1;
    }
    /*@
    loop invariant flag != 0 ==> i % 2 == 0;
    loop invariant flag == 0 ==> i % 2 == 1;
    loop invariant flag != 0 ==> j == i + 1;
    loop invariant flag != 0 ==> a == b;
    loop invariant flag == 0 ==> j <= i;
    loop invariant flag == 0 ==> 2 * j == i + 1;
    loop invariant 0 <= a <= UINT_MAX;
    loop invariant 0 <= b <= UINT_MAX;
    loop invariant 0 <= i <= UINT_MAX;
    loop invariant 0 <= j <= UINT_MAX;
    loop assigns j;
    loop assigns i;
    loop assigns b;
    loop assigns a;
    */
    while (unknown()) {
        a++;
        b += (j - i);
        i += 2;
        if (i%2 == 0) {
            j += 2;
        } else {
            j++;
        }
    }
    if (flag) {
        // @ assert(a == b);
    }
    return 0;
}
