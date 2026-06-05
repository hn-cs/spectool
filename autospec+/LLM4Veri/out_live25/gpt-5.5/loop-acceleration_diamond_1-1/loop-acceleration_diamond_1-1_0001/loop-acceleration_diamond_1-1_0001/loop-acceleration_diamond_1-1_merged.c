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
  loop invariant y % 2 == 0 ==> x % 2 == 0;
  loop invariant y % 2 != 0 ==> x <= 99;
  loop invariant x <= 100;
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
  //@ assert((x % 2) == (y % 2));
}
