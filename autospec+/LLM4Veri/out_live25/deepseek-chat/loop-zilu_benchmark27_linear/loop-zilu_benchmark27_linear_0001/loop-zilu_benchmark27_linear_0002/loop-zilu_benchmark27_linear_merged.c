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
  int k = unknown();
  if (!(i<j && k>i-j)) return 0;
  /*@
  loop invariant k - i == \at(k, Pre) - \at(i, Pre);
  loop invariant i - j <= 0;
  loop invariant i - \at(i, LoopEntry) == k - \at(k, LoopEntry);
  loop invariant i + k == \at(i, Pre) + \at(k, Pre);
  loop invariant i + k == \at(i, LoopEntry) + \at(k, LoopEntry);
  loop invariant \old(k) - \old(i) == k - i;
  loop invariant j - i;
  loop invariant i <= j;
  loop invariant i - j + \old(i) - \old(k) < k;
  loop invariant i - \old(i) == k - \old(k);
  loop invariant i + k == \old(i) + \old(k);
  loop assigns k;
  loop assigns i;
  */
  while (i<j) {
    k=k+1;
    i=i+1;
  }
  //@ assert(k > 0);
  return 0;
}
