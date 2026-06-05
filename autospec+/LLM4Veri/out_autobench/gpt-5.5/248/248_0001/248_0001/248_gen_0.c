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
  loop invariant i0 == k;
  loop invariant 0 <= i0;
  loop invariant n0 >= 0 ==> i0 <= n0;
  loop assigns i0, k;
  loop variant n0 - i0;
  */
  while( i0 < n0 ) {
    i0++;
    k++;
  }

  int i1 = 0;
  while( i1 < n1 ) {
    i1++;
    k++;
  }

  int j1 = 0;
  while( j1 < n0 + n1 ) {
      // @ assert(k > 0);
      j1++;
      k--;
  }
}