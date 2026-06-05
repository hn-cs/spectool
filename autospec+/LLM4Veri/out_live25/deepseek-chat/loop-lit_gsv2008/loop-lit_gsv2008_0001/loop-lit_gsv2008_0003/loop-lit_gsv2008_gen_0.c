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
    loop invariant x + y >= 0;
    loop invariant x >= -50;
    loop invariant -1000 <= y;
    loop invariant (x < 0) ==> (y >= -1000);
    loop invariant x + y >= -150;
    loop invariant y == -1000 ==> x >= -50;
    loop invariant y <= INT_MAX;
    loop invariant y - \at(y, Pre) == x - \at(x, Pre);
    loop invariant x >= -50 && y >= -1000;
    loop invariant x >= -50 && y >= -1000 && y <= INT_MAX;
    loop invariant x >= -50 && y >= -1000 && (y <= INT_MAX);
    loop invariant x == -50 ==> y >= -1000;
    loop invariant \at(x, Pre) + \at(y, Pre) <= \at(x, Pre) + \at(y, Pre);
    loop invariant 0 <= x + y;
    loop invariant -50 <= x;
    loop invariant -50 <= x + y;
    loop invariant -1000 <= y;
    loop invariant -1000 <= x;
    loop invariant -1000 < y;
    loop invariant (x < 0) ==> (x + y >= 0);
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
