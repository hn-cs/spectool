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
  loop invariant 0 <= x - \at(x, Pre) <= 1024 - \at(x, Pre);
  loop invariant \at(x, Pre) <= x <= 1024;
  loop assigns x, y;
  */
  while (x < 1024) {
    x++;
    y++;
  }
  // @ assert(x == y);
}
