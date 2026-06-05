#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include "assert.h"
int main() {
  int n;
  int i = 0;
  int k = 0;
  n = unknown();
  /*@
  loop invariant i == k && 0 <= i <= n;
  loop invariant n - i == n - k;
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
  loop invariant 0 <= j;
  loop assigns k;
  loop assigns j;
  */
  while( j < n ) {
    // @ assert(k > 0);
    j++;
    k--;
  }
}
