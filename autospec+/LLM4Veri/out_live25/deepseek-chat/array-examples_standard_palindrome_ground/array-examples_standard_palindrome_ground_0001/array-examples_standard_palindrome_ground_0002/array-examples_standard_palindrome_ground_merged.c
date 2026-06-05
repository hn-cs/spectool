#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define N 100000
int main( ) {
  int A[N];
  int i;
	/*@
	loop invariant i <= N;
	loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= A[k] <= INT_MAX;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns A[0..N-1];
	*/
	for (i = 0; i < N ; i++ ) {
    A[i] = unknown();
  }
  /*@
  loop invariant i <= N/2;
  loop invariant \forall integer k; i <= k < N/2 ==> A[k] == \at(A[k], Pre);
  loop invariant \forall integer k; N/2 <= k < N - i ==> A[k] == \at(A[k], Pre);
  loop invariant \forall integer k; N - i <= k < N ==> A[k] == \at(A[k], Pre);
  loop invariant \forall integer k; 0 <= k < i ==> A[k] == A[N - k - 1];
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns A[0..N/2-1];
  */
  for (i = 0; i < N/2 ; i++ ) {
    A[i] = A[N-i-1];
  }
  int x;
  for ( x = 0 ; x < N/2 ; x++ ) {
    // @ assert(A[x] == A[N - x - 1]  ); 
  }
  return 0;
}
