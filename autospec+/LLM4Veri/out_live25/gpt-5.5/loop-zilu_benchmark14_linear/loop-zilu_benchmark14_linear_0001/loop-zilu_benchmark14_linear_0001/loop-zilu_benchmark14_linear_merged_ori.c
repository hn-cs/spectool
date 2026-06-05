#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
int main() {
  int i = unknown();
  if (!(i>=0 && i<=200)) return 0;
  /*@
  loop invariant i;
  loop invariant i <= 200;
  loop invariant 0 <= i;
  loop assigns i;
  */
  while (i>0) {
    i--;
  }
  // @ assert(i>=0);
  return 0;
}
