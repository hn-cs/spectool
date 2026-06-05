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
  loop invariant INT_MIN <= x < INT_MAX;
  loop invariant INT_MIN <= y < INT_MAX;
  loop assigns x, y;
  */
  while (x < 1024) {
    x++;
    y++;
  }
  // @ assert(x == y);
}
