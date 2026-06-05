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
  int n = unknown();
  if (!(x>=0 && x<=y && y<n)) return 0;
  /*@
  loop invariant x >= \at(x, PreLoop);
  loop invariant y >= \at(y, PreLoop);
  loop invariant n == \at(n, PreLoop);
  loop invariant x <= n;
  loop invariant y <= n;
  loop invariant x <= y + 1;
  loop invariant x - y <= n - \at(y, PreLoop);
  loop assigns x, y;
  loop variant n - x;
  */
  while (x<n) {
    x++;
    if (x>y) y++;
  }
  // @ assert(y==n);
  return 0;
}
