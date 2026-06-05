#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include "assert.h"
int main(int argc, char* argv[]) {
  int c1 = 4000;
  int c2 = 2000;
  int c3 = 10000;
  int n, v;
  int i, k, j;
  n = unknown();
  if (!(0 <= n && n < 10)) return 0;
  k = 0;
  i = 0;
  /*@
  loop invariant \forall integer t; 0 <= t < i ==> 0 <= v[t] <= 2;
  loop invariant n - i;
  loop invariant k == (c1 * (\num_of(0, v, 0, i) + (\num_of(1, v, 0, i) * (c2/c1)) + (\num_of(2, v, 0, i) * (c3/c1))));
  loop invariant i <= n;
  loop invariant \forall integer t; 0 <= t < i ==> v[t] == 0 || v[t] == 1 || v[t] == 2;
  loop invariant \forall integer t; 0 <= t < i ==> \at(v, Pre) >= 0 && \at(v, Pre) < 2;
  loop invariant 0 <= k;
  loop invariant 0 <= i;
  loop assigns v;
  loop assigns k;
  loop assigns i;
  */
  while( i < n ) {
    i++;
    v = unknown();
    if (!(0 <= v && n < 2)) return 0;
    if( v == 0 )
      k += c1;
    else if( v == 1 )
      k += c2;
    else
      k += c3;
  }
  j = 0;
  /*@
  loop invariant n - j;
  loop invariant k == \at(k, LoopEntry) - j;
  loop invariant j <= n;
  loop invariant \at(k, LoopEntry) - j == k;
  loop invariant 0 <= k;
  loop invariant 0 <= j;
  loop assigns k;
  loop assigns j;
  */
  while( j < n ) {
    // @ assert(k > 0);
    j++;
    k--;
  }
  return 0;
}
