#include "assert.h"
int main() {
    int x = 0;
    int y = 50;
    /*@
    loop invariant x <= 100;
    loop invariant 100 - x;
    loop invariant 0 <= x;
    loop invariant (x >= 50 ==> y == x);
    loop invariant (x <= 50 ==> y == 50);
    loop assigns y;
    loop assigns x;
    */
    while(x < 100) {
	if (x < 50) {
	    x = x + 1;
	} else {
	    x = x + 1;
	    y = y + 1;
	}
    }
    // @ assert(y == 100);
    return 0;
}
