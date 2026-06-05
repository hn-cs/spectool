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
	long long sum[1];
	long long *a = malloc(sizeof(long long)*N);
	long long *b = malloc(sizeof(long long)*N);
	sum[0] = 0;
	/*@
	loop invariant i <= N;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] == 1;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..N-1];
	*/
	for(i=0; i<N; i++)
	{
		a[i] = 1;
	}
	/*@
	loop invariant sum[0] == 0;
	loop invariant i <= N;
	loop invariant \forall integer k; 0 <= k < i ==> b[k] == 1;
	loop invariant \forall integer k; 0 <= k < N ==> a[k] == 1;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns b[0..N-1];
	*/
	for(i=0; i<N; i++)
	{
		b[i] = 1;
	}
	/*@
	loop invariant sum[0] == i;
	loop invariant i <= N;
	loop invariant \forall integer k; 0 <= k < N ==> b[k] == 1;
	loop invariant \forall integer k; 0 <= k < N ==> a[k] == 1;
	loop invariant 0 <= i;
	loop assigns sum[0];
	loop assigns i;
	*/
	for(i=0; i<N; i++)
	{
		sum[0] = sum[0] + a[i];
	}
	/*@
	loop invariant sum[0] == N + i;
	loop invariant i <= N;
	loop invariant \forall integer k; 0 <= k < N ==> b[k] == 1;
	loop invariant \forall integer k; 0 <= k < N ==> a[k] == 1;
	loop invariant 0 <= i;
	loop assigns sum[0];
	loop assigns i;
	*/
	for(i=0; i<N; i++)
	{
		sum[0] = sum[0] + b[i];
	}
	/*@
	loop invariant 0 <= i <= N;
	loop invariant sum[0] == 2 * N;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] == 2 * N + 1;
	loop invariant \forall integer k; i <= k < N ==> a[k] == 1;
	loop assigns i;
	loop assigns a[0..N-1];
	loop variant N - i;
	*/
	for(i=0; i<N; i++)
	{
		a[i] = a[i] + sum[0];
	}
	for(i=0; i<N; i++)
	{
		// @ assert(a[i] == 2*N + 1);
	}
	return 1;
}
