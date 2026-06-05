#include "assert.h"
int main() {
    int i,j,k;
    i = 0;
    k = 9;
    j = -100;
    /*@
    loop invariant k == 4 || k == 9;
    loop invariant i <= 101;
    loop invariant 101 - i;
    loop invariant 0 <= i;
    loop invariant -100 <= j;
    loop assigns k;
    loop assigns j;
    loop assigns i;
    */
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
	/*@
	loop invariant k == 4;
	loop assigns k;
	*/
	while (k <= 3) {
	    k = k + 1;
	}
    }
    // @ assert(k == 4);
    return 0;
}
