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
  if (!(x < 0)) return 0;
  /*@
  loop invariant x == \old(x) + (y-\old(y))*(\old(y) + y - 1)/2;
  loop invariant x < 0 && y >= 0;
  loop invariant \old(y) <= y;
  loop invariant \old(x) < 0;
  loop assigns y;
  loop assigns x;
  */
  while (1) {
    if (x>=0) {
      break;
    } else {
      x=x+y; y++;
    }
  }
  // @ assert(y>=0);
  return 0;
}
