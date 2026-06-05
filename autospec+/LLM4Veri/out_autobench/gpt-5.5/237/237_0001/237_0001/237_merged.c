#include <limits.h>
/*@
    ensures 0 <= \result <= 1;
*/
int unknown_int();
int main() {
    int i,j,k;
    i = 1;
    j = 1;
    k = unknown_int();
    /*@
    loop invariant i <= INT_MAX;
    loop invariant i + k <= 2;
    loop invariant 1 <= i;
    loop invariant 1 <= i + k;
    loop assigns k;
    loop assigns j;
    loop assigns i;
    */
    while (i < INT_MAX) {
	i = i + 1;
	j = j + k;
	k = k - 1;
	//@ assert(1 <= i + k && i + k <= 2 && i >= 1);
    }
    return 0;
}