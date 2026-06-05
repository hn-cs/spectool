#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
int main(void) {
  unsigned int x = 0;
  /*@
  loop invariant x % 4 == 0;
  loop invariant x / 4 == (x - \at(x, Pre)) / 4 + \at(x, Pre) / 4;
  loop invariant x == \at(x, Pre) + 4 * (x - \at(x, Pre)) / 4;
  loop invariant x / 4 == (x - x % 4) / 4;
  loop invariant x % 4 == 0;
  loop invariant 0 <= x;
  loop invariant 0 <= (x/4);
  loop assigns x;
  */
  while (unknown()) {
    x += 4;
  }
  // @ assert(!(x % 4));
  return 0;
}
