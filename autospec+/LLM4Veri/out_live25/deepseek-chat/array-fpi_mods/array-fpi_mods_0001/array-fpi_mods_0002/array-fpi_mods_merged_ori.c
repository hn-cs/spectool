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
	sum[0] = 0;
	/*@
	loop invariant i <= N;
	loop invariant \forall integer j; 0 <= j < i ==> a[j] == 1;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..N-1];
	*/
	for(i=0; i<N; i++)
	{
		a[i] = 1;
	}
	/*@
	loop invariant sum[0] == i;
	loop invariant i <= N;
	loop invariant \forall integer k; 0 <= k < N ==> a[k] == 1;
	loop invariant 0 <= i;
	loop assigns sum[0];
	loop assigns i;
	*/
	for(i=0; i<N; i++)
	{
		sum[0] = sum[0] + a[i];
	}
	for(i=0; i<N; i++)
	{
		a[i] = a[i] + sum[0];
	}
	for(i=0; i<N; i++)
	{
		a[i] = a[i] % (sum[0] + 1);
	}
	for(i=0; i<N; i++)
	{
		// @ assert(a[i] == 0);
	}
	return 1;
}
