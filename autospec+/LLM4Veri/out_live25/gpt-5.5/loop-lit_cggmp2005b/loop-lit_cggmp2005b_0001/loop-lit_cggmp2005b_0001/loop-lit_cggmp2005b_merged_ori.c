#include "assert.h"
int main() {
    int i,j,k;
    i = 0;
    k = 9;
    j = -100;
    while (i <= 100) {
	i = i + 1;
	/*@
	loop invariant i <= 101;
	loop invariant 1 <= i;
	loop invariant -100 <= j;
	loop assigns j;
	*/
	while (j < 20) {
	    j = i + j;
	}
	k = 4;
	while (k <= 3) {
	    k = k + 1;
	}
    }
    // @ assert(k == 4);
    return 0;
}
