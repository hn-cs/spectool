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
  loop invariant x + y <= \at(x, Pre) + \at(y, Pre) + 3 * (y - x + 1);
  loop invariant \exists integer d; 0 <= d <= 7 && x == \at(x, Pre) + 7*d;
  loop invariant (x < 0 ==> x % 7 == \at(x, Pre) % 7) && (x >= 0 ==> x % 10 == \at(x, Pre) % 10);
  loop invariant (y < 0 ==> y % 10 == \at(y, Pre) % 10) && (y >= 0 ==> y % 3 == \at(y, Pre) % 3);
  loop invariant y - x;
  loop invariant x <= y + 16;
  loop invariant x < y;
  loop invariant \at(x, Pre) <= x && \at(y, Pre) <= y;
  loop assigns y;
  loop assigns x;
  */
  while (x<y) {
    if (x < 0) x = x + 7;
    else x = x + 10;
    if (y < 0) y = y - 10;
    else y = y + 3;
  }
  // @ assert(x >= y && x <= y + 16);
  return 0;
}
