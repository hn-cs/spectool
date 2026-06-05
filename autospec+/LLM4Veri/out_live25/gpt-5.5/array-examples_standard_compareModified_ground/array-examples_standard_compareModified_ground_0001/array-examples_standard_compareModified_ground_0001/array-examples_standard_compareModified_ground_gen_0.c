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
	loop invariant 0 <= j <= SIZE;
	loop invariant \forall integer k; 0 <= k < j ==> INT_MIN <= a[k] < INT_MAX;
	loop invariant \forall integer k; 0 <= k < j ==> INT_MIN <= b[k] < INT_MAX;
	loop assigns j, a[0..SIZE-1], b[0..SIZE-1];
	loop variant SIZE - j;
	*/
	for (int j = 0; j < SIZE ; j++ ) {
    a[j] = unknown();
		b[j] = unknown();
  }
  while ( i < SIZE ) {
    if ( a[i] != b[i] ) {
      rv = 0;
    }
    c[i] = a[i];
    i = i+1;
  }
  int x;
  if ( rv ) {
    for ( x = 0 ; x < SIZE ; x++ ) {
      // @ assert(a[x] == b[x]  );
    }
  }
  for ( x = 0 ; x < SIZE ; x++ ) {
    // @ assert(a[x] == c[x]  );
  }
  return 0;
}
