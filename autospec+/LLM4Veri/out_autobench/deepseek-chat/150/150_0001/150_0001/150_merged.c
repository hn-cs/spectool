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
