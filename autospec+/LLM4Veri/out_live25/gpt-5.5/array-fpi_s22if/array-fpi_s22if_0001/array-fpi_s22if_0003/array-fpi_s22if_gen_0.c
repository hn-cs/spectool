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
	loop invariant i <= N;
	loop invariant \forall integer k; i <= k < N ==> a[k] == 1;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] == 3;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..N-1];
	*/
	for(i=0; i<N; i++)
	{
		if(a[i] == 1) {
			a[i] = a[i] + 2;
		} else {
			a[i] = a[i] - 1;
		}
	}
	/*@
	loop invariant 0 <= i <= N;
	loop invariant \forall integer k; 0 <= k < N ==> a[k] == 3;
	loop invariant sum[0] == 3LL * i;
	loop assigns i;
	loop assigns sum[0];
	*/
	for(i=0; i<N; i++)
	{
		if(a[i] == 3) {
			sum[0] = sum[0] + a[i];
		} else {
			sum[0] = sum[0] * a[i];
		}
	}
	// @ assert(sum[0] == 3*N);
	return 1;
}
