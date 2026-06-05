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
  loop invariant 0 <= i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= A[k] < INT_MAX;
  loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= B[k] < INT_MAX;
  loop assigns i, A[0..N-1], B[0..N-1];
  loop variant N - i;
  */
  for (i = 0; i < N ; i++) {
    A[i] = unknown();
    B[i] = unknown();
  }	
	for (i = 0; i < N ; i++) {
    if ( A[i] == B[i] ) {
      C[j] = i;
      j = j + 1;
    }
  }
  int x; 
  for ( x = 0 ; x < j ; x++ ) {
    // @ assert(C[x] <= x + i - j  );
  }
  for ( x = 0 ; x < j ; x++ ) {
    // @ assert(C[x] >= x  );
  }
  return 0;
}
