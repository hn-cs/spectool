#include <limits.h>
/*@
    ensures \result >= INT_MIN && \result <= INT_MAX;
*/
int unknown_int();

int main() {
  int n,i,k;
  n = unknown_int();
  k = n;
  i = 0;

  /*@
  loop invariant k == n - i/2;
  loop invariant i%2 == 0;
  loop invariant 0 <= i;
  loop invariant 0 <= i/2;
  loop assigns k;
  loop assigns i;
  */
  while( i < n ) {
    k--;
    i = i + 2;
  }

  int j = 0;
 
  /*@
  loop invariant n - i/2 <= k;
  loop invariant k == n - j - i/2;
  loop invariant k == n - i/2 - j;
  loop invariant k == n - (i/2) - j;
  loop invariant k <= n;
  loop invariant 0 <= j;
  loop assigns k;
  loop assigns j;
  */
  while( j < n/2 ) {
    // @ assert(k > 0);
    k--;
    j++;
  }
  return 0;
}