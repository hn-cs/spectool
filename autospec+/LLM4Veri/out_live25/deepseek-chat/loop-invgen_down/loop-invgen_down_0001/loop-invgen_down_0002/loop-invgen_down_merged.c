#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include "assert.h"
int main() {
  int n;
  int k = 0;
  int i = 0;
  n = unknown();
  /*@
  loop invariant k == i;
  loop invariant 0 <= i;
  loop assigns k;
  loop assigns i;
  */
  while( i < n ) {
      i++;
      k++;
  }
  int j = n;
  /*@
  loop invariant k == i - (n - j);
  loop invariant j <= n;
  loop invariant 0 <= k;
  loop assigns k;
  loop assigns j;
  */
  while( j > 0 ) {
      //@ assert(k > 0);
      j--;
      k--;
  }
  return 0;
}
