#include "assert.h"
int main() {
    int i,j,k;
    i = 0;
    k = 9;
    j = -100;
    while (i <= 100) {
	i = i + 1;
	/*@
	loop invariant k == 9;
	loop invariant j == -100;
	loop invariant i <= 101;
	*/
	while (j < 20) {
	    j = i + j;
	}
	k = 4;
	/*@
	loop assigns k;
	*/
	while (k <= 3) {
	    k = k + 1;
	}
    }
    // @ assert(k == 4);
    return 0;
}
