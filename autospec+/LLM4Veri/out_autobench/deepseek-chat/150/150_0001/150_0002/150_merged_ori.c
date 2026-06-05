#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();

void foo(int n)
{
 int k=1;
 int i=1;
 int j=0;
 /*@
 loop invariant k == (i*(i+1))/2;
 loop invariant j == 0;
 loop invariant i <= n;
 loop invariant 1 <= i;
 loop invariant 0 <= i;
 loop assigns k;
 loop assigns j;
 loop assigns i;
 */
 while(i < n) {
  j = 0;
  /*@
  loop invariant k == \at(k, Pre) + \sum_(\lambda integer m; (i - m), 0, j-1);
  loop invariant j <= i;
  loop invariant i - j;
  loop invariant 0 <= j;
  loop assigns k;
  loop assigns j;
  */
  while(j < i) {
      k += (i-j);
      j++;
  }
  i++;
 }
 // @ assert(k >= n);
 
}
