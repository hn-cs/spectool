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
	/*@
	loop invariant j <= SIZE;
	loop invariant \forall integer k; 0 <= k < j ==> \valid(&a[k]) && \valid(&b[k]);
	loop invariant 0 <= j;
	loop assigns j;
	loop assigns b[0..SIZE-1];
	loop assigns a[0..SIZE-1];
	*/
	for (int j = 0; j < SIZE ; j++ ) {
    a[j] = unknown();
		b[j] = unknown();
  }
  int i = 0;
  int rv = 1;
  /*@
  loop invariant 0 <= i <= SIZE;
  loop invariant rv == 1 ==> \forall integer k; 0 <= k < i ==> a[k] == b[k];
  loop invariant rv == 0 ==> \exists integer k; 0 <= k < i && a[k] != b[k];
  loop assigns i, rv;
  loop variant SIZE - i;
  */
  while ( i < SIZE ) {
    if ( a[i] != b[i] ) {
      rv = 0;
    }
    i = i+1;
  }
  if ( rv ) {
    int x;
    for ( x = 0 ; x < SIZE ; x++ ) {
      // @ assert(a[x] == b[x]  );
    }
  }
  return 0;
}
