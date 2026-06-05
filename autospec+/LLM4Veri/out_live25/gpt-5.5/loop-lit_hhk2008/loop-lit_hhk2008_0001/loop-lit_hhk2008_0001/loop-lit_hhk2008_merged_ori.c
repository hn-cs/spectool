#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include "assert.h"
int main() {
    int a = unknown();
    int b = unknown();
    int res, cnt;
    if (!(a <= 1000000)) return 0;
    if (!(0 <= b && b <= 1000000)) return 0;
    res = a;
    cnt = b;
    /*@
    loop invariant res < INT_MAX;
    loop invariant res + cnt == a + b;
    loop invariant cnt;
    loop invariant cnt <= b;
    loop invariant INT_MIN <= res;
    loop invariant 0 <= cnt;
    loop assigns res;
    loop assigns cnt;
    */
    while (cnt > 0) {
	cnt = cnt - 1;
	res = res + 1;
    }
    // @ assert(res == a + b);
    return 0;
}
