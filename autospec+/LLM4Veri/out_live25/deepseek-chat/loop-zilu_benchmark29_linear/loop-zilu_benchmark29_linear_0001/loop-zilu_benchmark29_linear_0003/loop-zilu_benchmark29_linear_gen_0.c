#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
int main() {
  int x = unknown();
  int y = unknown();
  if (!(x<y)) return 0;
  /*@
  loop invariant \at(x, Pre) <= x <= \at(x, Pre) + 100 * ((x - \at(x, Pre)) / 100) + 99;
  loop invariant x - \at(x, Pre) == 100 * ((x - \at(x, Pre)) / 100);
  loop invariant \exists integer k; 0 <= k && x == \at(x, Pre) + 100*k;
  loop invariant y == \at(y, Pre);
  loop invariant y - x;
  loop invariant x >= \at(x, Pre) && y == \at(y, Pre);
  loop invariant x < y ==> x + 100 > y;
  loop invariant x - \at(x, Pre) == 100 * ((x - \at(x, Pre)) / 100);
  loop invariant \at(x, Pre) <= x;
  loop invariant \at(x, Pre) <= x && x <= \at(x, Pre) + 100 * (x - \at(x, Pre)) / 100;
  loop assigns x;
  */
  while (x<y) {
    x=x+100;
  }
  // @ assert(x >= y && x <= y + 99);
  return 0;
}
