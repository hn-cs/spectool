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
  if (!(x == y && x >= 0)) return 0;
  /*@
  loop invariant x;
  loop invariant x == y;
  loop invariant 0 <= y;
  loop invariant 0 <= x;
  loop assigns y;
  loop assigns x;
  */
  while (x > 0) {
    x--;
    y--;
  }
  // @ assert(y>=0);
  return 0;
}
