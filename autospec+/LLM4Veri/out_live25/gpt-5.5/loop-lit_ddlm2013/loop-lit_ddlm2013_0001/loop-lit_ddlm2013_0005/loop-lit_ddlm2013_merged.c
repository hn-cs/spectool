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
    loop invariant flag != 0 ==> j % 2 == 1;
    loop invariant flag != 0 ==> i % 2 == 0;
    loop invariant flag != 0 ==> a == b;
    loop invariant j <= UINT_MAX;
    loop invariant i <= UINT_MAX;
    loop invariant flag == 0 || flag != 0;
    loop invariant b <= UINT_MAX;
    loop invariant a <= UINT_MAX;
    loop invariant 0 <= j;
    loop invariant 0 <= i;
    loop invariant 0 <= b;
    loop invariant 0 <= a;
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
