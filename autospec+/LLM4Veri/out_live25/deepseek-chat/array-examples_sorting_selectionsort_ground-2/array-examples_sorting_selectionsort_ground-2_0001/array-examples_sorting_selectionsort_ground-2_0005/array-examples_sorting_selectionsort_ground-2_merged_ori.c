#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define N 100000
int main( ) {
  int a[ N ];
  int i = 0;
  int x;
  int y;
	/*@
	loop invariant i <= N;
	loop invariant \forall integer k; i <= k < N ==> a[i-1] <= a[k];
	loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; k < l < i ==> a[k] <= a[l];
	loop invariant N - i;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..N-1];
	*/
	for(int i = 0; i < N; i++) 
	{
	    a[i] = unknown();
	}
	i = 0;
  while ( i < N ) {
    int k = i + 1;
    int s = i;
    /*@
    loop invariant s <= k;
    loop invariant s < k;
    loop invariant k <= N;
    loop invariant i <= s;
    loop invariant \forall integer j; i <= j < k ==> a[s] <= a[j];
    loop assigns s;
    loop assigns k;
    */
    while ( k < N ) {
      if ( a[k] < a[s] ) {
        s = k;
      }
      k = k+1;
    }
    if ( s != i ) {
      int tmp = a[s];
      a[s] = a[i];
      a[i] = tmp;
    }
    /*@
    loop invariant i <= N;
    loop invariant \forall integer k; i <= k < N ==> \forall integer l; i <= l < N ==> a[i-1] <= a[l];
    loop invariant \forall integer k; 0 <= k < i ==> a[k] <= a[i];
    loop invariant \forall integer k; 0 <= k < i ==> a[k] <= a[i-1];
    loop invariant \forall integer k; 0 <= k < i ==> \forall integer l; k < l < i ==> a[k] <= a[l];
    loop invariant 0 <= i;
    */
    for ( x = 0 ; x < i ; x++ ) {
      /*@
      loop invariant x <= i;
      loop invariant x < i;
      loop invariant \forall integer p, q; 0 <= p < q < i ==> a[p] <= a[q];
      loop invariant \forall integer k; 0 <= k <= x ==> a[k] <= a[x];
      loop invariant \forall integer k; 0 <= k < x ==> a[k] <= a[k+1];
      loop invariant 0 <= x;
      loop assigns y;
      loop assigns x;
      */
      for ( y = x + 1 ; y < i ; y++ ) {
        // @ assert(a[x] <= a[y]  );
      }
    }
    /*@
    loop invariant x <= N;
    loop invariant i <= x;
    loop invariant i < N;
    loop invariant \forall integer k; i <= k < x ==> a[k] >= a[i];
    loop invariant 0 <= i;
    loop assigns x;
    */
    for ( x = i ; x < N ; x++ ) {
      // @ assert(a[x] >= a[i]  );
    }
    i = i+1;
  }
  for ( x = 0 ; x < N ; x++ ) {
    for ( y = x + 1 ; y < N ; y++ ) {
      // @ assert(a[x] <= a[y]  );
    }
  }
  return 0;
}
