#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
int main() {
  int i = unknown();
  if (!(i < 10 && i > -10)) return 0;
  /*@
  loop invariant i < 10;
  loop invariant i * i < 100;
  loop invariant 10 - i;
  loop invariant -10 < i;
  loop assigns i;
  */
  while (i * i < 100) {
    i = i + 1;
  }
  // @ assert(i == 10);
  return 0;
}
