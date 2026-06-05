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
    loop invariant 0 <= a <= a;
    loop invariant b == a;
    loop invariant i == (flag ? 2*a : 2*a + 1);
    loop invariant j == 2*a + 1;
    loop assigns a, b, i, j;
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
