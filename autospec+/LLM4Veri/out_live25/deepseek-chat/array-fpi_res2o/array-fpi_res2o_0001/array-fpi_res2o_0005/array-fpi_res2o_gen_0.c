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
	int *b = malloc(sizeof(int)*N);
	int *c = malloc(sizeof(int)*N);
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
	loop invariant i <= N;
	loop invariant \forall integer j; 0 <= j < i ==> b[j] == 1;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns b[0..N-1];
	*/
	for(i=0; i<N; i++)
	{
		b[i] = 1;
	}
	/*@
	loop invariant i <= N;
	loop invariant \forall integer j; 0 <= j < i ==> c[j] == 1;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns c[0..N-1];
	*/
	for(i=0; i<N; i++)
	{
		c[i] = 1;
	}
	/*@
	loop invariant i <= N;
	loop invariant 0 <= i;
	loop assigns sum[0];
	loop assigns i;
	*/
	for(i=0; i<N; i++)
	{
		sum[0] = sum[0] + a[i];
	}
	/*@
	loop invariant i <= N;
	loop invariant 0 <= i;
	loop invariant sum[0] == i + N;
	loop assigns sum[0];
	loop assigns i;
	*/
	for(i=0; i<N; i++)
	{
		sum[0] = sum[0] + b[i];
	}
	for(i=0; i<N; i++)
	{
		sum[0] = sum[0] + c[i];
	}
	// @ assert(sum[0] <= 3*N);
	return 1;
}
