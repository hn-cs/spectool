#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
/*@
loop invariant x == \at(x, Pre);
loop invariant t == \at(t, Pre);
loop invariant t <= y;
loop invariant \at(y, Pre) <= y;
loop assigns y;
loop invariant x == \at(x, Pre);
loop invariant t == \at(t, Pre);
loop invariant t <= y;
loop invariant \at(y, Pre) <= y;
loop assigns y;
*/
int main() {
  int x = unknown();
  int y = unknown();
  int t = unknown();
  if (!(x!=y && y==t)) return 0;
  /*@
  loop invariant x > 0 ? y >= \at(y, Pre) + x : y == \at(y, Pre);
  loop invariant x == \at(x, Pre);
  loop invariant t == \at(t, Pre);
  loop invariant t <= y;
  loop invariant \forall integer k; x > 0 ? y >= \at(y, Pre) + x : y == \at(y, Pre);
  loop invariant \at(y, Pre) <= y;
  loop invariant \at(t, Pre) <= y;
  loop assigns y;
  */
  while (unknown()) {
    if(x>0) y=y+x;
  }
  // @ assert(y>=t);
  return 0;
}
