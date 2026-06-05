#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define SIZE 100000
int main( ) {
  int a[SIZE];
  int b[SIZE];
  int i = 0;
  int c [SIZE];
  int rv = 1;
	/*@
	loop invariant j <= SIZE;
	loop invariant \forall integer k; 0 <= k < j ==> b[k] == \at(b[k], Pre);
	loop invariant \forall integer k; 0 <= k < j ==> a[k] == \at(a[k], Pre);
	loop invariant SIZE - j;
	loop invariant 0 <= j;
	loop assigns j;
	loop assigns b[0..SIZE-1];
	loop assigns a[0..SIZE-1];
	*/
	for (int j = 0; j < SIZE ; j++ ) {
    a[j] = unknown();
		b[j] = unknown();
  }
  /*@
  loop invariant rv == 1 ==> \forall integer k; 0 <= k < i ==> a[k] == b[k];
  loop invariant rv == 0 ==> \exists integer k; 0 <= k < i && a[k] != b[k];
  loop invariant i <= SIZE;
  loop invariant \forall integer k; i <= k < SIZE ==> c[k] == \at(c[k], Pre);
  loop invariant \forall integer k; 0 <= k < i ==> c[k] == a[k];
  loop invariant 0 <= i;
  loop assigns rv;
  loop assigns i;
  loop assigns c[0..SIZE-1];
  */
  while ( i < SIZE ) {
    if ( a[i] != b[i] ) {
      rv = 0;
    }
    c[i] = a[i];
    i = i+1;
  }
  int x;
  if ( rv ) {
    /*@
    loop invariant x <= SIZE;
    loop invariant \forall integer k; 0 <= k < x ==> a[k] == b[k];
    loop invariant 0 <= x;
    loop assigns x;
    */
    for ( x = 0 ; x < SIZE ; x++ ) {
      // @ assert(a[x] == b[x]  );
    }
  }
  for ( x = 0 ; x < SIZE ; x++ ) {
    // @ assert(a[x] == c[x]  );
  }
  return 0;
}
