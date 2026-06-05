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
  
  for (i=0;i<n;i++)
    /*@
    loop assigns j;
    loop assigns k;
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
