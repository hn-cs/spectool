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
  loop invariant n > 0 ==> i <= n;
  loop invariant n <= 0 ==> i == 0;
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
  while( j < n ) {
    // @ assert(k > 0);
    j++;
    k--;
  }
}
