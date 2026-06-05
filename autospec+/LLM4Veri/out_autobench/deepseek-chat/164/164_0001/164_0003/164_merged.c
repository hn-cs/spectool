#include <assert.h>
int unknown1();

/*
 * "nest-if8" from InvGen benchmark suite
 */

void main() {
  int i, j, k, n, m;
  if (m + 1 < n);
  else return;
  /*@
  loop invariant i <= n;
  loop invariant i % 4 == 0;
  loop invariant \forall integer t; 0 <= t < i ==> (t >= n || t < m);
  loop invariant \exists integer t; t >= i && t < n;
  loop invariant 0 <= i;
  loop assigns k;
  loop assigns j;
  loop assigns i;
  */
  for (i = 0; i < n; i += 4) {
    /*@
    loop invariant n - i;
    loop invariant i <= n;
    loop invariant i % 4 == 0;
    loop invariant \forall integer t; 0 <= t < i ==> (t >= n || t < m);
    loop invariant \exists integer t; t >= i && t < n;
    loop invariant 0 <= i;
    loop assigns k;
    loop assigns j;
    loop assigns i;
    */
    for (j = i; j < m;) {
      if (unknown1()) {
        //@ assert(j >= 0);
        j++;
        k = 0;
        /*@
        loop invariant k == \old(k) + (k - \old(k));
        loop invariant k <= j;
        loop invariant 0 <= k;
        loop assigns k;
        */
        while (k < j) {
          k++;
        }
      } else {
        //@ assert(n + j + 5 > i);
        j += 2;
      }
    }
  }
}