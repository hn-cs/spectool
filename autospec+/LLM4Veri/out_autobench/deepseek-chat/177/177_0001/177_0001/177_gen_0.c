#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();

/*
 * Adapted from ex20 from NECLA Static Analysis Benchmarks
 */

void foo(int k, int flag)
{
  int i=0;
  int j=0;
  int n;
  int __BLAST_NONDET;

  if (flag == 1){
     n=1;
  } else {
     n=2;
  }

  i=0;

  /*@
  loop invariant 0 <= i <= k+1;
  loop invariant j == i * n;
  loop invariant n == 1 || n == 2;
  loop assigns i, j;
  loop variant k - i + 1;
  */
  while ( i <= k) {
    i++;
    j = j + n;
  }
  if(flag == 1) {
    // @ assert(j == i);
  }
	
}


