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
  if (!(x == 4*y && x >= 0)) return 0;
  /*@
  loop invariant x == 4 * y;
  loop invariant 0 <= y;
  loop invariant 0 <= x;
  loop assigns y;
  loop assigns x;
  */
  while (x > 0) {
    x-=4;
    y--;
  }
  //@ assert(y>=0);
  return 0;
}
