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
    loop invariant j == 2*a + 3 || j == 2*a + 1;
    loop invariant j <= i + a + 2;
    loop invariant i == a/2;
    loop invariant i == 2*a || i == 2*a+1;
    loop invariant b == 0;
    loop invariant a == b;
    loop invariant a <= a;
    loop invariant 1 <= j || 0 <= i;
    loop invariant 0 <= i;
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
