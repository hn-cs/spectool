#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();

/*
 * Based on ex16 from NECLA Static Analysis Benchmarks
 */

int foo(int x, int y)
{
  int i=0;
  int t=y;
   
  if (x==y) return x;
  
  /*@
  loop invariant x == y ==> y >= t;
  loop invariant x != y ==> y >= t;
  loop invariant x == y ==> \false;
  loop invariant x != y;
  loop invariant y >= t;
  loop assigns y;
  loop assigns i;
  */
  while (unknown1()){
    if (x > 0)   
      y = y + x;
  }
   
  // @ assert(y >= t);
  return 0;
}


