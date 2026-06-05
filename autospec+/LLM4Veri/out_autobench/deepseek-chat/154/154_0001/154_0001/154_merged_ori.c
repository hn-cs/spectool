#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();

/*@
requires n > 0;
requires n < 10;
*/
void foo(int n) {
  int c1 = 4000;
  int c2 = 2000;
  int v;
  int i, k, j;
  k = 0;
  i = 0;
  /*@
  loop invariant n - i;
  loop invariant i <= n;
  loop invariant i * c2 <= k;
  loop invariant i * 2000 <= k;
  loop invariant 0 <= i;
  loop assigns k;
  loop assigns i;
  */
  while( i < n ) {
    i++;
    if(unknown2() % 2 == 0) 
      v = 0;
    else v = 1;
    
    if( v == 0 )
      k += c1;
    else 
      k += c2;
  }
  
  // @ assert(k > n);
}

