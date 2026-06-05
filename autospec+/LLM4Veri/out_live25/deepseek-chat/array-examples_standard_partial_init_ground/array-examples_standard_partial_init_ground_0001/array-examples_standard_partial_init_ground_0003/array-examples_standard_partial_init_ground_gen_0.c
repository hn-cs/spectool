#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define N 100000
int main ( ) {
  int A[ N ];
  int B[ N ];
  int C[ N ]; 
  int i;
  int j = 0;
  /*@
  loop invariant i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> A[k] == \at(A[k], Pre) && B[k] == \at(B[k], Pre);
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns B[0..N-1];
  loop assigns A[0..N-1];
  */
  for (i = 0; i < N ; i++) {
    A[i] = unknown();
    B[i] = unknown();
  }	
	/*@
	loop invariant j <= i;
	loop invariant i <= N;
	loop invariant \forall integer k; 0 <= k < j-1 ==> C[k] < C[k+1];
	loop invariant \forall integer k; 0 <= k < j ==> C[k] < i;
	loop invariant \forall integer k; 0 <= k < j ==> A[C[k]] == B[C[k]];
	loop invariant \forall integer k; 0 <= k < j ==> (\forall integer m; 0 <= m < C[k] ==> A[m] != B[m]);
	loop invariant 0 <= j;
	loop invariant 0 <= i;
	loop assigns j;
	loop assigns i;
	loop assigns C[0..N-1];
	*/
	for (i = 0; i < N ; i++) {
    if ( A[i] == B[i] ) {
      C[j] = i;
      j = j + 1;
    }
  }
  int x; 
  /*@
  loop invariant 0 <= x <= j;
  loop invariant \forall integer k; 0 <= k < x ==> C[k] < C[k+1];
  loop invariant \forall integer k; 0 <= k < x ==> C[k] < i;
  loop invariant \forall integer k; 0 <= k < x ==> A[C[k]] == B[C[k]];
  loop assigns x;
  loop variant j - x;
  */
  for ( x = 0 ; x < j ; x++ ) {
    // @ assert(C[x] <= x + i - j  );
  }
  for ( x = 0 ; x < j ; x++ ) {
    // @ assert(C[x] >= x  );
  }
  return 0;
}
