#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
int main() {
  int n = unknown();
  int i = unknown();
  int l = unknown();
  i = l;
  if (!(l>0)) return 0;
  /*@
  loop invariant 0 <= i <= n;
  loop invariant i >= l;
  loop assigns i;
  */
  while (i < n) {
    i++;
  }
  // @ assert(l>=1);
  return 0;
}
