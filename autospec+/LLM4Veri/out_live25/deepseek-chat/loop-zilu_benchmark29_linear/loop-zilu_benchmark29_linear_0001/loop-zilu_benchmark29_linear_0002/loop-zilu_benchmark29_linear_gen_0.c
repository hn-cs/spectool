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
  loop invariant x >= \at(x, Pre);
  loop invariant y == \at(y, Pre);
  loop invariant \at(x, Pre) <= x && x <= \at(x, Pre) + 100 * (x - \at(x, Pre)) / 100;
  loop invariant x - \at(x, Pre) == 100 * ((x - \at(x, Pre)) / 100);
  loop invariant x < y ==> x + 100 > y;
  loop invariant y - x;
  loop invariant x >= \at(x, Pre) && y == \at(y, Pre);
  loop invariant x < y ==> x + 100 > y;
  loop assigns x;
  */
  while (x<y) {
    x=x+100;
  }
  // @ assert(x >= y && x <= y + 99);
  return 0;
}
