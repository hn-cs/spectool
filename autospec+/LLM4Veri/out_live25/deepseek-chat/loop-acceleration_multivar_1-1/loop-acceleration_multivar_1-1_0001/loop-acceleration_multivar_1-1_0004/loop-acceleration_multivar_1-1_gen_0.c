#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
int main(void) {
  int x = unknown();
  int y = x;
  /*@
  loop invariant x == y;
  loop invariant x <= 1024;
  loop invariant y <= 1024;
  loop invariant x >= \at(x, Pre);
  loop invariant y >= \at(y, Pre);
  loop invariant x == y;
  loop invariant x <= 1024;
  loop invariant x - \at(x, Pre) == y - \at(y, Pre);
  loop invariant x - \at(x, Pre) <= 1024 - \at(x, Pre);
  loop invariant \at(x, Pre) <= x;
  loop invariant 0 <= x - \at(x, Pre);
  loop invariant 0 <= x - \at(x, Pre) && x - \at(x, Pre) <= 1024 - \at(x, Pre);
  loop assigns y;
  loop assigns x;
  */
  while (x < 1024) {
    x++;
    y++;
  }
  // @ assert(x == y);
}
