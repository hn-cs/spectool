#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result <= INT_MAX/4;
*/
int unknown();
#include<stdlib.h>
int N;
int main()
{
	N = unknown();
	if(N <= 0) return 1;
	// @ assert (N <= 2147483647/4);
	int i;
	int *a = malloc(sizeof(int)*N);
	/*@
	loop invariant i <= N;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] <= INT_MAX/4;
	loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= a[k] <= INT_MAX/4;
	loop invariant N <= INT_MAX/4;
	loop invariant 0 <= i;
	loop invariant 0 < N;
	loop assigns i;
	loop assigns a[0..N-1];
	*/
	for(i=0; i<N; i++)
	{
		a[i] = unknown();
	}
	/*@
	loop invariant \forall integer k; i <= k < N ==> INT_MIN <= a[k] <= INT_MAX/4;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] == N || a[k] < N;
	loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= a[k];
	loop invariant \forall integer k; 0 <= k < N ==> INT_MIN <= a[k] <= INT_MAX/4;
	loop invariant N <= INT_MAX/4;
	loop invariant 0 < N;
	loop invariant i <= N;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] <= N;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..N-1];
	*/
	for(i=0; i<N; i++)
	{
		if(a[i] < N) {
			a[i] = a[i];
		} else {
			a[i] = N;
		}
	}
	/*@
	loop invariant i <= N;
	loop invariant \forall integer k; 0 <= k < N ==> a[k] <= N;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns \nothing;
	*/
	for(i=0; i<N; i++)
	{
		// @ assert(a[i] <= N);
	}
	return 1;
}
