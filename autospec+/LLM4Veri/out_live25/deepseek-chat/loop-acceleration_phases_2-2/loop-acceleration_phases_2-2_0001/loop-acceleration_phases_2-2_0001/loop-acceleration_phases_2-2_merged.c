#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
int main(void) {
  int x = 1;
  int y = unknown();
  if (!(y > 0)) return 0;
  /*@
  loop invariant x <= y;
  loop invariant 1 <= x;
  loop invariant 0 < y;
  loop assigns x;
  */
  while (x < y) {
    if (x < y / x) {
      x *= x;
    } else {
      x++;
    }
  }
  //@ assert(x == y);
}
