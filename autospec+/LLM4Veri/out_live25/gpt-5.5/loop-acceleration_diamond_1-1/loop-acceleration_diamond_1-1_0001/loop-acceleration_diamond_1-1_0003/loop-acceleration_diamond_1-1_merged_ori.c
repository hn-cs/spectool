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
  loop invariant y <= INT_MAX;
  loop invariant y < INT_MAX;
  loop invariant y % 2 == 0 || x <= 99;
  loop invariant y % 2 != 0 || x % 2 == 0;
  loop invariant x == 100 ==> y % 2 == 0;
  loop invariant x <= 101;
  loop invariant x < 99 ==> x <= 98;
  loop invariant x < 101;
  loop invariant x < 101 || y < INT_MAX;
  loop invariant x != 101;
  loop invariant INT_MIN <= y;
  loop invariant INT_MIN <= y || y < INT_MAX;
  loop invariant INT_MIN <= y || x < 101;
  loop invariant INT_MIN < y;
  loop invariant y == \at(y,Pre);
  loop invariant y % 2 == 0 ==> x <= 100;
  loop invariant y % 2 == 0 ==> x % 2 == 0;
  loop invariant y % 2 != 0 ==> x <= 99;
  loop invariant y % 2 != 0 ==> x < 100;
  loop invariant x <= 99 || (y % 2 == 0 && x == 100);
  loop invariant x <= 100;
  loop invariant x % 2 == 0 || x <= 99;
  loop invariant 99 <= x ==> x == 99 || x == 100;
  loop invariant 0 <= x;
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
