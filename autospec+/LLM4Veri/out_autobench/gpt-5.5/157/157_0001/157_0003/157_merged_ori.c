#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();

/*
 * "nested5.c" from InvGen test suite
 */

void main() {
  int i,j,k,n;
  
  /*@
  loop invariant n < 0 || i <= n;
  loop invariant 0 <= i;
  loop assigns k;
  loop assigns j;
  loop assigns i;
  */
  for (i=0;i<n;i++)
    /*@
    loop invariant n - j;
    loop invariant j <= n;
    loop invariant i <= j;
    loop assigns k;
    loop assigns j;
    */
    for (j=i;j<n;j++)
      /*@
      loop invariant k <= n;
      loop invariant j <= k;
      loop invariant i <= k;
      loop invariant i <= j;
      loop assigns k;
      */
      for (k=j;k<n;k++){
	      // @ assert(k>=i);
      }
}
