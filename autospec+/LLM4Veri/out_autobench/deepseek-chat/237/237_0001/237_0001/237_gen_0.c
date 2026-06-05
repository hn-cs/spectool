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
    loop invariant 1 <= i <= INT_MAX;
    loop invariant i + k == 2;
    loop invariant i >= 1;
    loop invariant k <= 1;
    loop invariant j == (i-1)* (2 - (i-1) + 1) / 2 + 1; // This is too complex, better to simplify
    loop invariant j == 1 + (i-1)*(2 - (i-1) + 1)/2; // Also complex
    // Simpler invariants capturing the relationship:
    loop invariant i + k == 2;
    loop invariant j == 1 + (i-1)*(4 - i)/2; // From k = 2 - i, sum of k values
    loop invariant 1 <= i + k <= 2;
    loop assigns i, j, k;
    */
    while (i < INT_MAX) {
	i = i + 1;
	j = j + k;
	k = k - 1;
	// @ assert(1 <= i + k && i + k <= 2 && i >= 1);
    }
    return 0;
}