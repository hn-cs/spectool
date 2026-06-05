#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
int main() {
  int low = unknown();
  int mid = unknown();
  int high = unknown();
  if (!(low == 0 && mid >= 1 && high == 2*mid)) return 0;
  /*@
  loop invariant mid <= \at(mid, Pre);
  loop invariant low + mid == \at(low, Pre) + \at(mid, Pre);
  loop invariant low + high == 2 * \at(mid, Pre);
  loop invariant 0 <= mid;
  loop assigns mid;
  loop assigns low;
  loop assigns high;
  */
  while (mid > 0) {
    low = low + 1;
    high = high - 1;
    mid = mid - 1;
  }
  // @ assert(low == high);
  return 0;
}
