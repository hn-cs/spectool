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
  loop invariant 0 <= n <= 2*k;
  loop invariant i - j == n % 2;
  loop invariant b == (n % 2 == 1);
  loop assigns i, j, b, n;
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
