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
  loop invariant i == k;
  loop invariant i <= n;
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
