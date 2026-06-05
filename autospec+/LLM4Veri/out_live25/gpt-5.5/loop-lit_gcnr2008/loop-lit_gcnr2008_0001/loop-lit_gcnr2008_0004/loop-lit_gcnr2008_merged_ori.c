#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include "assert.h"
int main() {
    int x,y,z,w;
    x = y = z = w = 0;
    /*@
    loop invariant y > 0 ==> x > 0;
    loop invariant y <= 10100;
    loop invariant y < 10100;
    loop invariant y < 10100 || x <= 10000;
    loop invariant x > 0 ==> y > 0;
    loop invariant x == 4 ==> y == 400;
    loop invariant x == 3 ==> y == 300;
    loop invariant x == 2 ==> y == 200;
    loop invariant x == 1 ==> y == 100;
    loop invariant x <= 10000;
    loop invariant x < 10000;
    loop invariant (y - x) % 99 == 0;
    loop invariant z == 10 * w;
    loop invariant z % 5 == 0;
    loop invariant z % 2 == 0;
    loop invariant z % 10 == 0;
    loop invariant y == 0 ==> x == 0;
    loop invariant y <= 10099;
    loop invariant y <= 100 * x;
    loop invariant y <= 100 * w;
    loop invariant x >= 4 ==> y >= x + 396;
    loop invariant x == 0 ==> y == 0;
    loop invariant x <= z;
    loop invariant x <= y;
    loop invariant x <= w;
    loop invariant x <= 4 ==> y == 100 * x;
    loop invariant x <= 10099;
    loop invariant x <= 10099 || y <= 10099;
    loop invariant x < 10099;
    loop invariant w == z / 10;
    loop invariant w <= z;
    loop invariant 10 <= z || w == 0;
    loop invariant 10 * x <= z;
    loop invariant 0 <= z;
    loop invariant 0 <= y;
    loop invariant 0 <= x;
    loop invariant 0 <= w;
    loop assigns z;
    loop assigns y;
    loop assigns x;
    loop assigns w;
    */
    while (unknown() && y < 10000) {
	if (unknown()) {
	    x = x + 1;
	    y = y + 100;
	} else if (unknown()) {
	    if (x >= 4) {
		x = x + 1;
		y = y + 1;
	    }
	} else if (y > 10*w && z >= 100*x) {
	    y = -y;
	}
	w = w + 1;
	z = z + 10;
    }
    // @ assert(x >= 4 && y <= 2);
    return 0;
}
