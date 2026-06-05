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
  int min = 0;
	/*@
	loop invariant j <= N;
	loop invariant \forall integer k; 0 <= k < j ==> INT_MIN <= a[k] < INT_MAX;
	loop invariant 0 <= j;
	loop assigns j;
	loop assigns a[0..N-1];
	*/
	for(int j = 0; j < N; j++)
	{
	  a[j] = unknown();
	}
  int i = 0;
  /*@
  loop invariant min <= a[i-1] || i == 0;
  loop invariant i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> min <= a[k];
  loop invariant N - i;
  loop invariant 0 <= i;
  loop assigns min;
  loop assigns i;
  */
  while ( i < N ) {
    if ( a[i] < min ) {
      min = a[i];
    }
    i = i + 1;
  }
  int x;
  /*@
  loop invariant 0 <= x <= N;
  loop invariant \forall integer k; 0 <= k < x ==> a[k] >= min;
  loop assigns x;
  loop variant N - x;
  */
  for ( x = 0 ; x < N ; x++ ) {
    // @ assert(a[x] >= min  );
  }
  return 0;
}
