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
loop assigns y;
*/
int main() {
  int x = unknown();
  int y = unknown();
  int t = unknown();
  if (!(x!=y && y==t)) return 0;
  while (unknown()) {
    if(x>0) y=y+x;
  }
  // @ assert(y>=t);
  return 0;
}
