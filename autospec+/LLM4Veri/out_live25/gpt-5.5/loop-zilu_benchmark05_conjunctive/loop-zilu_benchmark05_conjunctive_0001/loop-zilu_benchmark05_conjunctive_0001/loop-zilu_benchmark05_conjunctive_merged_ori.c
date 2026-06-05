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
  loop invariant y <= n;
  loop invariant x <= y;
  loop invariant x <= n;
  loop invariant n - x;
  loop invariant 0 <= x;
  loop assigns y;
  loop assigns x;
  */
  while (x<n) {
    x++;
    if (x>y) y++;
  }
  // @ assert(y==n);
  return 0;
}
