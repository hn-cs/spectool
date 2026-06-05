#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define N 100000
int main( ) {
  int a[N];
  int max = 0;
	/*@
	loop invariant j <= N;
	loop invariant \forall integer k; 0 <= k < j ==> INT_MIN <= a[k] < INT_MAX;
	loop invariant N - j;
	loop invariant 0 <= j;
	loop assigns j;
	loop assigns a[0..N-1];
	*/
	for (int j = 0; j < N ; j++ ) {
    a[j] = unknown();
  }
  int i = 0;
  /*@
  loop invariant 0 <= i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] <= max;
  loop assigns i;
  loop assigns max;
  loop variant N - i;
  */
  while ( i < N ) {
    if ( a[i] > max ) {
      max = a[i];
    }
    i = i + 1;
  }
  int x;
  for ( x = 0 ; x < N ; x++ ) {
    // @ assert(a[x] <= max  );
  }
  return 0;
}
