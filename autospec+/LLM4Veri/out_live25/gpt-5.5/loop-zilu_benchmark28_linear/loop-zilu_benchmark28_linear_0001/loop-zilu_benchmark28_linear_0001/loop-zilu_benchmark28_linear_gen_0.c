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
  if (!(i * i < j * j)) return 0;
  /*@
  loop invariant i * i <= j * j;
  loop invariant i < j ==> 0 < j;
  loop invariant i < j ==> -j <= i < j;
  loop assigns i, j;
  */
  while (i < j) {
    j = j - i;
    if (j < i) {j = j + i;
    i = j - i;
    j = j - i;}
  }
  // @ assert(j == i);
  return 0;
}
