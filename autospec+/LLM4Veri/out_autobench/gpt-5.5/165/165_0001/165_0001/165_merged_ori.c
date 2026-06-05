#include <assert.h>

/*
 * "split.c" from InvGen benchmark suite
 */

void main() {
  int k = 100;
  int b;
  int i;
  int j;
  int n;
  i = j;
  /*@
  loop invariant n <= 2*k;
  loop invariant n % 2 == 1 ==> ((b == 0 ==> i == j + 1) && (b != 0 ==> j == i + 1));
  loop invariant n % 2 == 0 ==> i == j;
  loop invariant k == 100;
  loop invariant 2*k - n;
  loop invariant 0 <= n;
  loop assigns n;
  loop assigns j;
  loop assigns i;
  loop assigns b;
  */
  for( n = 0 ; n < 2*k ; n++ ) {
    if(b) {
      i++;
    } else {
      j++;
    }
    b = !b;
  }
  // @ assert(i == j);
}
