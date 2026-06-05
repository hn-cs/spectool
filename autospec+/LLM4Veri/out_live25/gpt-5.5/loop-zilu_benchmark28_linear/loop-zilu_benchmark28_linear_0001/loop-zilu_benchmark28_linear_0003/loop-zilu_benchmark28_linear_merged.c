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
  loop invariant j <= i ==> i - j >= 0;
  loop invariant j < 0 ==> j <= i;
  loop invariant i < j ==> j >= 1;
  loop invariant i < j ==> i + 1 <= j;
  loop invariant i < j ==> 0 < j - i;
  loop invariant j <= i || 0 < j;
  loop invariant j <= i || -j <= i;
  loop invariant j != 0;
  loop invariant i < j ==> j - i > 0;
  loop invariant i < j ==> i <= j - 1;
  loop invariant i < j ==> i * i < j * j;
  loop invariant i < j ==> 0 < j;
  loop invariant i < j ==> -j <= i < j;
  loop invariant i * i <= j * j;
  loop assigns j;
  loop assigns i;
  */
  while (i < j) {
    j = j - i;
    if (j < i) {j = j + i;
    i = j - i;
    j = j - i;}
  }
  //@ assert(j == i);
  return 0;
}
