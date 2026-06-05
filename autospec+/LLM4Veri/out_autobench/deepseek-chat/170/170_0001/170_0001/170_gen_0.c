#include <assert.h>

int unknown1();
int unknown2();
int unknown3();
int unknown4();

/*
 * Taken from "Counterexample Driven Refinement for Abstract Interpretation" (TACAS'06) by Gulavani
 */
/*@
requires n > 0;
*/
void foo(int n) {
  int x = 0;
  int m = 0;
  /*@
  loop invariant 0 <= x <= n;
  loop invariant 0 <= m < n;
  loop invariant m < x;
  loop invariant m <= x;
  loop invariant m == x - 1 || m < x - 1;
  loop invariant \forall integer k; 0 <= k < x ==> (unknown1() ? m == k : m < k);
  loop assigns x, m;
  loop variant n - x;
  */
  while (x < n) {
    if (unknown1()) {
      m = x;
    }
    x = x + 1;
  }
  if (n > 0) {
    // @ assert(0 <= m && m < n);
  }
}