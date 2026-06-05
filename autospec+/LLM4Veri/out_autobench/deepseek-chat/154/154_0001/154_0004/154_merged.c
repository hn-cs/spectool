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
  loop invariant k == i * c2 + (v == 0 ? (c1 - c2) * ??? : 0);
  loop invariant v == 0 || v == 1;
  loop invariant k >= 2000 * i && k <= 4000 * i;
  loop invariant k <= i * c1 + (n - i) * c2;
  loop invariant k <= i * c1 + (n - i) * c2 || \at(k, Pre) <= k;
  loop invariant k <= \at(k, Pre) + 4000 * n;
  loop invariant k <= \at(k, Pre) + 4000 * n || k <= i * c1 + (n - i) * c2;
  loop invariant k <= \at(k, Pre) + 4000 * n || \at(k, Pre) <= k;
  loop invariant k < i * c1 + (n - i) * c2;
  loop invariant k < \at(k, Pre) + 4000 * n;
  loop invariant i <= n;
  loop invariant i * c2 <= k;
  loop invariant i * c2 <= k || k <= i * c1 + (n - i) * c2;
  loop invariant i * c2 <= k || k <= \at(k, Pre) + 4000 * n;
  loop invariant i * c2 <= k || \at(k, Pre) <= k;
  loop invariant i * c2 < k;
  loop invariant \at(k, Pre) <= k;
  loop invariant \at(k, Pre) < k;
  loop invariant \at(k, Pre) < k;
  loop invariant \at(k, Pre) < k;
  loop invariant 0 <= i;
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
  
  //@ assert(k > n);
}

