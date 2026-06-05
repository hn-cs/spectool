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
	a[0] = 10;
	b[0] = 1;
	/*@
	loop invariant \forall integer k; 0 <= k < i ==> a[k] == 10 * (k + 1);
	loop invariant i <= N;
	loop invariant 1 <= i;
	loop assigns i;
	loop assigns a[0..N-1];
	*/
	for(i=1; i<N; i++)
	{
		a[i] = a[i-1] + 10;
	}
	/*@
	loop invariant i <= N;
	loop invariant 1 <= i;
	loop assigns i;
	loop assigns b[0..N-1];
	*/
	for(i=1; i<N; i++)
	{
		b[i] = b[i-1] + a[i-1];
	}
	/*@
	loop invariant i <= N;
	loop invariant 0 <= i;
	loop assigns i;
	*/
	for(i=0; i<N; i++)
	{
		// @ assert(b[i] == 5*i*i + 5*i + 1);
	}
	return 1;
}
