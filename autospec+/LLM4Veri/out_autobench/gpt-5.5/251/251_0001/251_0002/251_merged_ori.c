#include <limits.h>
/*@
ensures INT_MIN <= \result <= INT_MAX;
*/
int unknown_int();

int main() {
  int n;
  int i = 0;
  int k = 0;
  n = unknown_int();
  /*@
  loop invariant n > 0 ==> i <= n;
  loop invariant i == k;
  loop invariant 0 <= i;
  loop assigns k;
  loop assigns i;
  */
  while( i < n ) {
	  i++;
	  k++;
  }

  int j = 0;
  /*@
  loop invariant n > 0 ==> j <= n;
  loop invariant n > 0 ==> i == n;
  loop invariant n - j;
  loop invariant k == i - j;
  loop invariant 0 <= j;
  loop assigns k;
  loop assigns j;
  */
  while( j < n ) {
    // @ assert (k > 0);
    j++;
    k--;
  }
}