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
  int b[N];
  int i;
	/*@
	loop invariant i <= N;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] == \at(a[k], Pre);
	loop invariant N - i;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..N-1];
	*/
	for( i = 0 ; i < N ; i++ ) {
    a[i] = unknown();
  }
  /*@
  loop invariant 0 <= i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> b[k] == a[N-k-1];
  loop assigns i, b[0..N-1];
  loop variant N - i;
  */
  for( i = 0 ; i < N ; i++ ) {
    b[i] = a[N-i-1];
  }
  int x;
  for ( x = 0 ; x < N ; x++ ) {
    // @ assert(a[x] == b[N-x-1]  );
  }
  return 0;
}
