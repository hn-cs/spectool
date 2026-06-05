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
	loop invariant j == 0 || INT_MIN <= a[j-1] < INT_MAX;
	loop invariant j <= N;
	loop invariant \valid(a + (0..N-1));
	loop invariant \forall integer k; 0 <= k < j ==> a[k] <= INT_MAX - 1;
	loop invariant \forall integer k; 0 <= k < j ==> a[k] != INT_MAX;
	loop invariant \forall integer k; 0 <= k < j ==> INT_MIN <= a[k] < INT_MAX;
	loop invariant N == 100000;
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
  loop invariant \valid(a + (0..N-1));
  loop invariant N == 100000;
  loop invariant INT_MIN <= max < INT_MAX;
  loop invariant \forall integer k; 0 <= k < N ==> INT_MIN <= a[k] < INT_MAX;
  loop invariant i == 0 ==> max == 0;
  loop invariant i > 0 ==> \exists integer k; 0 <= k < i && max == a[k] || max == 0;
  loop invariant max >= 0 || \exists integer k; 0 <= k < i && max == a[k];
  loop invariant i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] <= max;
  loop invariant N - i;
  loop invariant 0 <= i;
  loop assigns max;
  loop assigns i;
  */
  while ( i < N ) {
    if ( a[i] > max ) {
      max = a[i];
    }
    i = i + 1;
  }
  int x;
  /*@
  loop invariant x <= N;
  loop invariant \forall integer k; 0 <= k < N ==> a[k] <= max;
  loop invariant N - x;
  loop invariant 0 <= x;
  loop assigns x;
  */
  for ( x = 0 ; x < N ; x++ ) {
    // @ assert(a[x] <= max  );
  }
  return 0;
}
