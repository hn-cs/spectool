#include <assert.h>

/*
 * "nested4.c" from InvGen benchmark suite
 */

/*@
requires l > 0;
requires n > l;
*/
void foo(int n, int l) {
  int i,k;


  /*@
  loop invariant 1 <= k <= n;
  loop invariant l > 0;
  loop invariant n > l;
  loop assigns k, i;
  loop variant n - k;
  */
  for (k=1; k<n; k++){
    /*@
    loop invariant n - i;
    loop invariant l <= i;
    loop invariant i <= n;
    loop invariant 1 <= i;
    loop assigns i;
    */
    for (i=l; i<n; i++) {
    }
    /*@
    loop invariant n - i;
    loop invariant l <= i;
    loop invariant i <= n;
    loop invariant 1 <= i;
    loop assigns i;
    */
    for (i=l; i<n; i++) {
      // @ assert(1<=i);
    }
  }

}
