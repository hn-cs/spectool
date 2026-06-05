#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
int main(void) {
  int x = 0;
  int y = unknown();
  /*@
  loop invariant y == \at(y, LoopEntry);
  loop invariant x == \at(x, LoopEntry) + (x - \at(x, LoopEntry));
  loop invariant (x % 2) == (y % 2) || (x % 2) == ((y + 1) % 2);
  loop invariant x <= 99;
  loop invariant x <= 100;
  loop invariant x < 100;
  loop invariant x % 2 == y % 2;
  loop invariant \at(x, Pre) == 0;
  loop invariant 0 <= x;
  loop invariant (x >= 0) && (x <= 100);
  loop invariant (x == 0) ==> (y % 2 == 0);
  loop invariant (x < 100) ==> (x % 2 == y % 2);
  loop invariant (x % 2) == (y % 2);
  loop assigns x;
  */
  while (x < 99) {
    if (y % 2 == 0) {
      x += 2;
    } else {
      x++;
    }
  }
  // @ assert((x % 2) == (y % 2));
}
