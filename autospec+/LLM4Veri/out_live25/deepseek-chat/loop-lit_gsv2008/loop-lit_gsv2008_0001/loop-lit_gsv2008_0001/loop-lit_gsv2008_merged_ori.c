#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include "assert.h"
int main() {
    int x,y;
    x = -50;
    y = unknown();
    if (!(-1000 < y && y < INT_MAX)) return 0;
    /*@
    loop invariant y <= INT_MAX;
    loop invariant x < 0;
    loop invariant -x;
    loop invariant -1000 <= x;
    loop invariant -1000 < y;
    loop assigns y;
    loop assigns x;
    */
    while (x < 0) {
	x = x + y;
	y++;
    }
    // @ assert(y > 0);
    return 0;
}
