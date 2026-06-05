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
  int z = unknown();
  if (!(x == y && x >= 0 && x+y+z==0)) return 0;
  /*@
  loop invariant z == -2 * x;
  loop invariant y == x;
  loop invariant x;
  loop invariant 0 <= x;
  loop assigns z;
  loop assigns y;
  loop assigns x;
  */
  while (x > 0) {
    x--;
    y--;
    z++;
    z++;
  }
  // @ assert(z<=0);
  return 0;
}
