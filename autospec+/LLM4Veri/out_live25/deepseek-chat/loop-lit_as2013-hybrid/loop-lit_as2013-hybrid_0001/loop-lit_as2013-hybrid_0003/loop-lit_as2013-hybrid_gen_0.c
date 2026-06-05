#include <assert.h>
int main() {
  int i = 0;
  /*@
  loop invariant i <= 10;
  loop invariant \at(i, Pre) == i;
  loop invariant 0 <= i;
  loop assigns j;
  loop assigns i;
  */
  while (1) {
    i++;
    int j = 0;
    /*@
    loop invariant i == \at(i, Pre) + 1;
    loop invariant j <= 10;
    loop invariant 0 <= j;
    loop invariant j >= 0;
    loop invariant j <= 10;
    loop invariant \at(i, Pre) == i - 1;
    loop invariant \forall integer k; 0 <= k < j ==> 1;
    loop invariant j <= 10;
    loop invariant i == \at(i, Pre) + 1;
    loop invariant 0 <= j;
    loop assigns j;
    */
    while (j < 10) {
      // @ assert(0 <= i);
      // @ assert(i <= 10);
      j++;
    }
    if (i > 9)
      i = 0;
  }
  return 0;
}
