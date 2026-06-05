#include <limits.h>
/*@
    ensures \result >= INT_MIN && \result <= INT_MAX;
*/
int unknown_int();

int main() {
  int n0, n1;
  int i0 = 0;
  int k = 0;

  n0 = unknown_int();
  n1 = unknown_int();

  /*@
  loop invariant k == i0;
  loop invariant 0 <= k;
  loop invariant 0 <= i0;
  loop assigns k;
  loop assigns i0;
  */
  while( i0 < n0 ) {
    i0++;
    k++;
  }

  int i1 = 0;
  /*@
  loop invariant n1 - i1 == k + n0 - (n0 + n1);
  loop invariant k == n0 + i1;
  loop invariant k == i0 + i1;
  loop invariant i1 <= n1;
  loop invariant n0 <= k;
  loop invariant 0 <= i1;
  loop assigns k;
  loop assigns i1;
  */
  while( i1 < n1 ) {
    i1++;
    k++;
  }

  int j1 = 0;
  /*@
  loop invariant 0 <= j1;
  loop assigns k;
  loop assigns j1;
  */
  while( j1 < n0 + n1 ) {
      // @ assert(k > 0);
      j1++;
      k--;
  }
}