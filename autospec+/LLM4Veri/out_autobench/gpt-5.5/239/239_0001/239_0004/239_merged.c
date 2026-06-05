#include <limits.h>
/*@
ensures INT_MIN <= \result <= INT_MAX;
*/
int unknown_int();
int main() {
	int n;
	int k = 0;
	int i = 0;
	n = unknown_int();

	/*@
	loop invariant n >= 0 ==> k <= n;
	loop invariant n >= 0 ==> i <= n;
	loop invariant n < 0 ==> k == 0;
	loop invariant n < 0 ==> i == 0;
	loop invariant k == i;
	loop invariant k <= n || k == 0;
	loop invariant i <= n || i == 0;
	loop invariant 0 <= k;
	loop invariant 0 <= i;
	loop assigns k;
	loop assigns i;
	*/
	while (i < n) {
		i++;
		k++;
	}
	int j = n;
	/*@
	loop invariant n >= 0 ==> k == j;
	loop invariant n >= 0 ==> 0 <= k <= n;
	loop invariant n >= 0 ==> 0 <= j <= n;
	loop invariant n < 0 ==> k == 0;
	loop invariant n < 0 ==> j == n;
	loop invariant k <= n || k == 0;
	loop invariant 0 <= k;
	loop invariant j <= n;
	loop assigns k;
	loop assigns j;
	*/
	while (j > 0) {
		//@ assert(k > 0);
		j--;
		k--;
	}

	return 0;
}