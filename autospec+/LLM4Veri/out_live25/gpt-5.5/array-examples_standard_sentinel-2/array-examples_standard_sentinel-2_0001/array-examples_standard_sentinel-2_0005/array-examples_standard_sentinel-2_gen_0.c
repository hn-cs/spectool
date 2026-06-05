#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define N 100000
int main ( ) {
  int a[N];
  int marker = unknown();
  int pos = unknown();
	/*@
	loop invariant 0 <= i <= N;
	loop invariant \valid(a + (0..i-1));
	loop invariant \forall integer k; 0 <= k < i ==> \valid(a + k);
	loop invariant \forall integer k; 0 <= k < i ==> a[k] != INT_MAX;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] <= INT_MAX - 1;
	loop invariant marker == \at(marker,LoopEntry);
	loop invariant pos == \at(pos,LoopEntry);
	loop invariant i <= N;
	loop invariant \valid(a + (0..N-1));
	loop invariant \forall integer k; 0 <= k < i ==> a[k] == \at(a[k],Here);
	loop invariant \forall integer k; 0 <= k < i ==> a[k] < INT_MAX;
	loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= a[k];
	loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= a[k] < INT_MAX;
	loop invariant N - i;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..N-1];
	*/
	for(int i = 0; i < N; i++) 
	{
	  a[i] = unknown();
	}
  if ( pos >= 0 && pos < N ) {
    a[ pos ] = marker;
    int i = 0;
    /*@
    loop invariant pos < N;
    loop invariant pos - i;
    loop invariant i <= pos;
    loop invariant i < N;
    loop invariant a[pos] == marker;
    loop invariant \valid(a + pos);
    loop invariant \valid(a + i);
    loop invariant \forall integer k; 0 <= k < i ==> k != pos;
    loop invariant \forall integer k; 0 <= k < i ==> a[k] != marker;
    loop invariant \exists integer k; i <= k <= pos && a[k] == marker;
    loop invariant 0 <= pos;
    loop invariant 0 <= i;
    loop assigns i;
    */
    while( a[ i ] != marker ) {
      i = i + 1;
    }
    // @ assert(i <= pos  );
  }
  return 0;
}
