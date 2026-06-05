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
	loop invariant i <= N;
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
    loop invariant 0 <= i <= pos;
    loop invariant pos < N;
    loop invariant a[pos] == marker;
    loop invariant \forall integer k; 0 <= k < i ==> a[k] != marker;
    loop assigns i;
    loop variant pos - i;
    */
    while( a[ i ] != marker ) {
      i = i + 1;
    }
    // @ assert(i <= pos  );
  }
  return 0;
}
