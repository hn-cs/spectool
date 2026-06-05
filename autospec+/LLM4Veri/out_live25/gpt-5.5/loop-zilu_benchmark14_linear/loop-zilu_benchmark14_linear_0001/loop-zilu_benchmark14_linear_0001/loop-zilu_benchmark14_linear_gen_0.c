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
  loop invariant 0 <= i <= 200;
  loop assigns i;
  loop variant i;
  */
  while (i>0) {
    i--;
  }
  // @ assert(i>=0);
  return 0;
}
