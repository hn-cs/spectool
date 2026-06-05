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
	loop invariant k == i;
	loop invariant 0 <= i;
	loop invariant n >= 0 ==> i <= n;
	loop assigns i, k;
	loop variant n - i;
	*/
	while (i < n) {
		i++;
		k++;
	}
	int j = n;
	while (j > 0) {
		// @ assert(k > 0);
		j--;
		k--;
	}

	return 0;
}