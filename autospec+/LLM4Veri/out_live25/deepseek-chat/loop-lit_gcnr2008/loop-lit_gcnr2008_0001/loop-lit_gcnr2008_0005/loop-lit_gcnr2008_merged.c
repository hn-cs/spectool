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
    loop invariant 0 <= z && z == 10 * w;
    loop invariant z == 10 * w;
    loop invariant y >= 0 ==> y <= 100*x;
    loop invariant y >= 0 ==> x >= 0;
    loop invariant y <= 100*x;
    loop invariant x >= 0 ==> y >= 0;
    loop invariant 0 <= z;
    loop invariant 0 <= y;
    loop invariant 0 <= y || y <= 100*x;
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
    //@ assert(x >= 4 && y <= 2);
    return 0;
}
