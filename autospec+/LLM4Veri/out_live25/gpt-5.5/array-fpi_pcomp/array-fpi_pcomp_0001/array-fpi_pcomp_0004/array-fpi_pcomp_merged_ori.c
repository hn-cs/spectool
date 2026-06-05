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
	long long i;
	long long *a = malloc(sizeof(long long)*N);
	long long *b = malloc(sizeof(long long)*N);
	long long *c = malloc(sizeof(long long)*N);
	a[0] = 6;
	b[0] = 1;
	c[0] = 0;
	/*@
	loop invariant i <= N;
	loop invariant 1 <= i;
	loop assigns i;
	loop assigns a[1..N-1];
	*/
	for(i=1; i<N; i++)
	{
		a[i] = a[i-1] + 6;
	}
	/*@
	loop invariant i <= N;
	loop invariant 1 <= i;
	loop assigns i;
	loop assigns b[1..N-1];
	*/
	for(i=1; i<N; i++)
	{
		b[i] = b[i-1] + a[i-1];
	}
	/*@
	loop invariant i <= N;
	loop invariant 1 <= i;
	loop assigns i;
	loop assigns c[1..N-1];
	*/
	for(i=1; i<N; i++)
	{
		c[i] = c[i-1] + b[i-1];
	}
	/*@
	loop invariant i <= N;
	loop invariant \forall integer k; 0 <= k < N ==> c[k] == k * k * k;
	loop invariant N - i;
	loop invariant 0 <= i;
	loop assigns i;
	*/
	for(i=0; i<N; i++)
	{
		// @ assert(c[i] == i*i*i);
	}
	return 1;
}
