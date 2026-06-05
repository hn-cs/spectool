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
  loop invariant k <= n;
  loop invariant j;
  loop invariant j == k;
  loop invariant j <= n;
  loop invariant 0 <= k;
  loop invariant 0 <= j;
  loop invariant 0 < n;
  loop assigns k;
  loop assigns j;
  */
  while (j>0 && n>0) {
    j--;k--;
  }
  // @ assert((k == 0));
  return 0;
}
