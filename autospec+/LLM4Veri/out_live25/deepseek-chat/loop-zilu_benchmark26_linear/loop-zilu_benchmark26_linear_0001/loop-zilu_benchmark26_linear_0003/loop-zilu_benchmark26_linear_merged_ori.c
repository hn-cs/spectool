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
  if (!(x<y)) return 0;
  /*@
  loop invariant 0 <= y - x;
  loop invariant 0 < y - x;
  loop invariant 0 < y - x;
  loop invariant 0 < y - x;
  loop invariant 0 < y - x;
  loop invariant 0 < y - x;
  loop invariant 0 < y - x;
  loop invariant 0 < y - x;
  loop invariant 0 < y - x;
  loop invariant 0 < y - x;
  loop invariant y == \old(y);
  loop invariant y - x;
  loop invariant y - x <= y - \old(x);
  loop invariant x == \old(x) + (x - \old(x));
  loop invariant x <= y;
  loop invariant x - \old(x) == y - \old(y);
  loop invariant \old(x) <= x;
  loop assigns x;
  */
  while (x<y) {
    x=x+1;
  }
  // @ assert(x==y);
  return 0;
}
