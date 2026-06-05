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
	loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= a[k] < INT_MAX;
	loop invariant N - i;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..N-1];
	*/
	for( i = 0 ; i < N ; i++ ) {
    a[i] = unknown();
  }
  /*@
  loop invariant i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> b[k] == a[N-k-1];
  loop invariant \forall integer k; 0 <= k < N ==> INT_MIN <= a[k] < INT_MAX;
  loop invariant N - i;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns b[0..N-1];
  */
  for( i = 0 ; i < N ; i++ ) {
    b[i] = a[N-i-1];
  }
  int x;
  /*@
  loop invariant 0 <= x <= N;
  loop invariant \forall integer k; 0 <= k < N ==> b[k] == a[N-k-1];
  loop invariant \forall integer k; 0 <= k < x ==> a[k] == b[N-k-1];
  loop assigns x;
  loop variant N - x;
  */
  for ( x = 0 ; x < N ; x++ ) {
    // @ assert(a[x] == b[N-x-1]  );
  }
  return 0;
}
