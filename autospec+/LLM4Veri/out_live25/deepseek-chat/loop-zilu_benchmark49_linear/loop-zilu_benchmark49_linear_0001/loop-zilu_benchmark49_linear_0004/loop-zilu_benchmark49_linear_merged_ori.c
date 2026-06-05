#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
int main() {
  int i = unknown();
  int j = unknown();
  int r = unknown();
  if (!(r > i + j)) return 0;
  /*@
  loop invariant i;
  loop invariant i == 0 ==> j == \old(i) + \old(j);
  loop invariant i <= \old(i);
  loop invariant i + j == \old(i) + \old(j);
  loop invariant i + j == \at(i, Pre) + \at(j, Pre);
  loop invariant i + j < r;
  loop invariant \forall integer k; 0 <= k <= \at(i, LoopEntry) - i ==> j == \at(j, LoopEntry) + k;
  loop invariant \at(i, LoopEntry) - i == j - \at(j, LoopEntry);
  loop invariant 0 <= j;
  loop invariant 0 <= i;
  loop assigns j;
  loop assigns i;
  */
  while (i > 0) {
    i = i - 1;
    j = j + 1;
  }
  // @ assert(r > i + j);
  return 0;
}
