#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
int main() {
  int i = unknown();
  int j = unknown();
  int k = unknown();
  if (!(i==0 && j==0)) return 0;
  /*@
  loop invariant k < INT_MAX;
  loop invariant k - i + 1;
  loop invariant j == i;
  loop invariant i <= k + 1;
  loop invariant 0 <= i;
  loop assigns j;
  loop assigns i;
  */
  while (i <= k) {
    i++;
    j=j+1;
  }
  // @ assert(j==i);
  return 0;
}
