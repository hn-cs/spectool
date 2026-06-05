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
  loop invariant \forall integer t; 0 <= t < i ==> \forall integer u; t <= u < n ==> \forall integer v; u <= v < n ==> v >= u;
  loop invariant \forall integer p, q, r; 0 <= p <= q <= r < i ==> r >= p;
  loop invariant 0 <= i;
  loop assigns k;
  loop assigns j;
  loop assigns i;
  */
  for (i=0;i<n;i++)
    /*@
    loop invariant j <= n;
    loop invariant i <= n;
    loop invariant i <= j;
    loop invariant \forall integer p, q, r; 0 <= p <= i && i <= q <= j && j <= r <= k ==> p <= r;
    loop invariant 0 <= j;
    loop invariant 0 <= i;
    loop assigns k;
    loop assigns j;
    loop assigns i;
    */
    for (j=i;j<n;j++)
      /*@
      loop invariant k <= n;
      loop invariant j <= n;
      loop invariant j <= k;
      loop invariant i <= n;
      loop invariant i <= j;
      loop invariant 0 <= k;
      loop invariant 0 <= j;
      loop invariant 0 <= i;
      loop assigns k;
      */
      for (k=j;k<n;k++){
	      //@ assert(k>=i);
      }
}
