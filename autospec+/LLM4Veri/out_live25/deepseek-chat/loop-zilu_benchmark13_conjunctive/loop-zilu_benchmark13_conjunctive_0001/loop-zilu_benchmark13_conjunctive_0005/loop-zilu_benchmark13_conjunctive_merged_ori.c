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
  if (!(i==0 && j==0)) return 0;
  /*@
  loop invariant i - j == 0;
  loop invariant k - i == \at(k, Pre) - \at(i, Pre) - (i - \at(i, Pre));
  loop invariant k - i + 1;
  loop invariant k - i + 1 == \at(k, Pre) - \at(i, Pre) + 1 - (i - \at(i, Pre));
  loop invariant j == i;
  loop invariant i == j;
  loop invariant i <= k + 1;
  loop invariant i < k + 1;
  loop invariant i < k + 1;
  loop invariant i < k + 1;
  loop invariant i < k + 1;
  loop invariant i < k + 1;
  loop invariant i < k + 1;
  loop invariant i < k + 1;
  loop invariant i < k + 1;
  loop invariant i < k + 1;
  loop invariant i < k + 1;
  loop invariant i < k + 1;
  loop invariant \at(k, Pre) <= k;
  loop invariant \at(k, Pre) - \at(i, Pre) + 1 == k - i + 1;
  loop invariant \at(i, Pre) == 0 && \at(j, Pre) == 0;
  loop invariant 0 <= i;
  loop assigns j;
  loop assigns i;
  */
  while (i <= k) {
    i++;
    j=j+1;
  }
  // @ assert(j==i);
  return 0;
}
