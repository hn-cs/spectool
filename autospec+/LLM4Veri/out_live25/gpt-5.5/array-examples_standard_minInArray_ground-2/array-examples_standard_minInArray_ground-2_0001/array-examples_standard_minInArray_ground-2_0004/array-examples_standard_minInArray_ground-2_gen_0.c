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
	loop invariant 0 <= j <= N;
	loop invariant \forall integer k; 0 <= k < j ==> INT_MIN <= a[k] < INT_MAX;
	loop invariant \forall integer k; j <= k < N ==> \true;
	loop invariant j < N ==> 0 <= j < N;
	loop invariant N == 100000;
	loop invariant j <= N;
	loop invariant N - j;
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
  loop invariant min <= 0;
  loop invariant i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] >= min;
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
  loop invariant x <= N;
  loop invariant \forall integer k; 0 <= k < N ==> a[k] >= min;
  loop invariant N - x;
  loop invariant 0 <= x;
  loop assigns x;
  */
  for ( x = 0 ; x < N ; x++ ) {
    // @ assert(a[x] >= min  );
  }
  return 0;
}
