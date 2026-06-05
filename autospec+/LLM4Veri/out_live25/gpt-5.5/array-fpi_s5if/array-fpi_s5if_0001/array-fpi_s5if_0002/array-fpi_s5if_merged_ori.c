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
	int *a = malloc(sizeof(int)*N);
	sum[0] = 0;
	/*@
	loop invariant sum[0] == 0;
	loop invariant i <= N;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] == 5;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..N-1];
	*/
	for(i=0; i<N; i++)
	{
		a[i] = 5;
	}
	/*@
	loop invariant sum[0] == 5LL * i;
	loop invariant i <= N;
	loop invariant \forall integer k; 0 <= k < N ==> a[k] == 5;
	loop invariant N - i;
	loop invariant 0 <= i;
	loop assigns sum[0];
	loop assigns i;
	*/
	for(i=0; i<N; i++)
	{
		if(a[i] == 5) {
			sum[0] = sum[0] + a[i];
		} else {
			sum[0] = sum[0] * a[i];
		}
	}
	// @ assert(sum[0] == 5*N);
	return 1;
}
