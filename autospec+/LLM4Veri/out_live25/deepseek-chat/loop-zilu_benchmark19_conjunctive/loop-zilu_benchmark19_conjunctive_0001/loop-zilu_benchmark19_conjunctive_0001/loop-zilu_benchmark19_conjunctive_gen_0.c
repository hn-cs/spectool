#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
int main() {
  int j = unknown();
  int k = unknown();
  int n = unknown();
  if (!((j==n) && (k==n) && (n>0))) return 0;
  /*@
  loop invariant 0 <= j <= \at(j, Pre) && 0 <= k <= \at(k, Pre);
  loop invariant j == k;
  loop invariant \at(j, Pre) - j == \at(k, Pre) - k;
  loop assigns j, k;
  loop variant j;
  */
  while (j>0 && n>0) {
    j--;k--;
  }
  // @ assert((k == 0));
  return 0;
}
