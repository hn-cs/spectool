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
  loop invariant 0 <= j <= i;
  loop invariant i == \at(i, LoopEntry);
  loop invariant n == \at(n, LoopEntry);
  loop invariant k == \at(k, LoopEntry) + j * i - (j * (j - 1)) / 2;
  loop assigns j, k;
  loop variant i - j;
  */
  while(j < i) {
      k += (i-j);
      j++;
  }
  i++;
 }
 // @ assert(k >= n);
 
}
