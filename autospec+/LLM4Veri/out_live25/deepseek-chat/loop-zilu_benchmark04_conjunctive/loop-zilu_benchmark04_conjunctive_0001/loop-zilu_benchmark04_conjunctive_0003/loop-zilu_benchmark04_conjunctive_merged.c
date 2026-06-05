#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
int main() {
  int k = unknown();
  int j = unknown();
  int n = unknown();
  if (!(n>=1 && k>=n && j==0)) return 0;
  /*@
  loop invariant k + j == \at(k, LoopEntry) + \at(j, LoopEntry);
  loop invariant \forall integer t; 0 <= t <= j && k == \at(k, LoopEntry) - t && j == \at(j, LoopEntry) + t;
  loop invariant n - j;
  loop invariant k + j == \at(k, Pre) + \at(j, Pre);
  loop invariant j <= n;
  loop invariant \exists integer t; 0 <= t <= j && k == \at(k, Pre) - t && j == \at(j, Pre) + t;
  loop invariant 0 <= k;
  loop invariant 0 <= j;
  loop assigns k;
  loop assigns j;
  */
  while (j<=n-1) {
    j++;
    k--;
  }
  //@ assert(k>=0);
  return 0;
}
