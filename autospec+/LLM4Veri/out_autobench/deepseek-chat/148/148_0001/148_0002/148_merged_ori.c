#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();

/*
 * from Invgen test suite
 */
/*@
requires n > 0;
requires k > n;
*/
int foo(int n, int k) {

  int i, j;

  j = 0;
  /*@
  loop invariant k == k - j;
  loop invariant n - j;
  loop invariant k + j == \at(k, Pre) + \at(j, Pre);
  loop invariant j <= n;
  loop invariant 0 <= k;
  loop invariant 0 <= j;
  loop assigns k;
  loop assigns j;
  */
  while( j < n ) {
    j++;
    k--;
  } 
  // @ assert(k>=0);
  return 0;
}
