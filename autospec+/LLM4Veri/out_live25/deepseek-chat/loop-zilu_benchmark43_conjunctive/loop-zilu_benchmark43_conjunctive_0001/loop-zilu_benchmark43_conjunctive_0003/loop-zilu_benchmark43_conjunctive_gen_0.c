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
  if (!(x < 100 && y < 100)) return 0;
  /*@
  loop invariant x <= 100;
  loop invariant y <= 100;
  loop invariant x == y;
  loop invariant x - y == \at(x - y, Pre);
  loop invariant x + y == \at(x, Pre) + \at(y, Pre) + 2 * (x - \at(x, Pre));
  loop invariant \at(y, Pre) <= y;
  loop invariant \at(x, Pre) <= x;
  loop invariant \at(x, Pre) - \at(y, Pre) == x - y;
  loop invariant 0 <= y;
  loop invariant 0 <= x;
  loop invariant (x >= 0 && y >= 0) || (x < 100 && y < 100);
  loop invariant y <= 100;
  loop invariant x == y;
  loop invariant x <= 100;
  loop invariant x - y == \at(x - y, Pre);
  loop invariant x + y == \at(x, Pre) + \at(y, Pre) + 2 * (x - \at(x, Pre));
  loop invariant \at(y, Pre) <= y;
  loop invariant \at(x, Pre) <= x;
  loop invariant \at(x, Pre) - \at(y, Pre) == x - y;
  loop invariant 0 <= y;
  loop invariant 0 <= x;
  loop invariant (x >= 0 && y >= 0) || (x < 100 && y < 100);
  loop invariant (100 - x) + (100 - y);
  loop assigns y;
  loop assigns x;
  */
  while (x < 100 && y < 100) {
    x=x+1;
    y=y+1;
  }
  // @ assert(x == 100 || y == 100);
  return 0;
}
