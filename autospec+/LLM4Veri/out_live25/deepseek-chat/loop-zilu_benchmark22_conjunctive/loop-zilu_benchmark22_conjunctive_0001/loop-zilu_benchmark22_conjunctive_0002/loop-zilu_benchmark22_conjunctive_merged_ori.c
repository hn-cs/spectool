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
  if (!(x==1 && y==0)) return 0;
  /*@
  loop invariant y <= x;
  loop invariant x == 1 + (y*(y-1))/2;
  loop invariant 0 <= x;
  loop invariant 0 <= y;
  loop assigns y;
  loop assigns x;
  */
  while (unknown()) {
    x=x+y;
    y++;
  }
  // @ assert(x >= y);
  return 0;
}
