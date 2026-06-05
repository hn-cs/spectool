#include <assert.h>

/*
  * "nested2.c" from InvGen benchmark suite
  */
/*@
requires l > 0;
*/
void foo(int l) {
  int i, k, n;

  for (k = 1; k < n; k++) {
    /*@
    loop invariant k >= 1;
    loop invariant k < n;
    loop invariant i >= 0;
    loop invariant i <= n;
    loop invariant \forall integer t; t >= l && t < i ==> t < n;
    loop invariant \forall integer t; t >= l && t < i ==> t < n;
    loop assigns i;
    loop assigns k;
    */
    for (i = l; i < n; i++) {

    }
    for (i = l; i < n; i++) {
      // @ assert(1 <= k);
    }
  }

}