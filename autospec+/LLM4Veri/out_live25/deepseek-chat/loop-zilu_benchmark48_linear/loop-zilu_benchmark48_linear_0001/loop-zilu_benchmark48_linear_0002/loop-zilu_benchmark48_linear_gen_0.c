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
  if (!(i<j && k> 0)) return 0;
  /*@
  loop invariant i <= j;
  loop invariant k == \at(k, Pre) + (i - \at(i, Pre));
  loop invariant \at(k, Pre) > 0 ==> k > i - \at(i, Pre);
  loop invariant \at(i, Pre) < \at(j, Pre);
  loop invariant k == \at(k, Pre) + (i - \at(i, Pre));
  loop invariant \forall integer t; i <= t <= j ==> k > t - \at(i, Pre);
  loop invariant k == \at(k, Pre) + (i - \at(i, Pre));
  loop invariant i <= j;
  loop invariant \at(k, Pre) > 0 ==> k > i - \at(i, Pre);
  loop invariant \at(i, Pre) < \at(j, Pre);
  loop assigns k;
  loop assigns i;
  */
  while (i<j) {
    k=k+1;i=i+1;
  }
  // @ assert(k > j - i);
  return 0;
}
