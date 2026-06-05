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
	int sum[1];
	int *a = malloc(sizeof(int)*N);
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
	loop invariant \forall integer j; 0 <= j < N ==> a[j] == 1;
	loop invariant 0 <= i;
	loop assigns sum[0];
	loop assigns i;
	*/
	for(i=0; i<N; i++)
	{
		sum[0] = sum[0] + a[i];
	}
	/*@
	loop invariant sum[0] == N;
	loop invariant i <= N;
	loop invariant \forall integer j; i <= j < N ==> a[j] == 1;
	loop invariant \forall integer j; 0 <= j < i ==> a[j] == 0;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..N-1];
	*/
	for(i=0; i<N; i++)
	{
		if(sum[0] == N) {
			a[i] = a[i] - 1;
		} else {
			a[i] = a[i] + 1;
		}
	}
	/*@
	loop invariant 0 <= i <= N;
	loop invariant sum[0] == N;
	loop invariant \forall integer j; 0 <= j < N ==> a[j] == 0;
	loop assigns i;
	*/
	for(i=0; i<N; i++)
	{
		// @ assert(a[i] == 0);
	}
	return 1;
}
