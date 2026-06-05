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
  loop invariant y < INT_MAX;
  loop invariant x == y;
  loop invariant x < INT_MAX;
  loop invariant INT_MIN <= y;
  loop invariant INT_MIN <= x;
  loop assigns y;
  loop assigns x;
  */
  while (x < 1024) {
    x++;
    y++;
  }
  // @ assert(x == y);
}
