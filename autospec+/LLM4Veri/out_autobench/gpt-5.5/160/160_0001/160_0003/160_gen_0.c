#include <assert.h>

/*
  * "nested2.c" from InvGen benchmark suite
  */
/*@
requires l > 0;
*/
void foo(int l) {
  int i, k, n;

  /*@
  loop invariant 1 <= k;
  loop invariant k <= n || n <= 1;
  loop assigns k, i;
  loop variant n - k;
  */
  for (k = 1; k < n; k++) {
    /*@
    loop invariant n - i;
    loop invariant l <= i;
    loop invariant i <= n || n < l;
    loop invariant 1 <= k;
    loop assigns i;
    */
    for (i = l; i < n; i++) {

    }
    /*@
    loop invariant n - i;
    loop invariant l <= i;
    loop invariant i <= n || n < l;
    loop invariant 1 <= k;
    loop assigns i;
    */
    for (i = l; i < n; i++) {
      // @ assert(1 <= k);
    }
  }

}