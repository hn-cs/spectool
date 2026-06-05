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
	/*@
	loop invariant i == 0 || a[i-1] >= 10;
	loop invariant i == 0 || a[i-1] == 10*i;
	loop invariant i <= N;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] > 0;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] == 10 + 10*k;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] == 10 * (k + 1);
	loop invariant \forall integer k; 0 <= k < i ==> a[k] % 10 == 0;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..N-1];
	*/
	for(i=0; i<N; i++)
	{
		if(i==0) {
			a[0] = 10;
		} else {
			a[i] = a[i-1] + 10;
		}
	}
	/*@
	loop invariant i == 0 || b[i-1] == 5*i*(i-1) + 1;
	loop invariant \forall integer k; 0 <= k < i ==> b[k] > 0;
	loop invariant \forall integer k; 0 <= k < i ==> b[k] == 5*k*k + 5*k + 1;
	loop invariant \forall integer k; 0 <= k < i ==> b[k] == 5*k*(k + 1) + 1;
	loop invariant \forall integer k; 0 <= k < i ==> b[k] % 10 == 1;
	loop invariant \forall integer k; 0 <= k < N ==> a[k] == 10 * (k + 1);
	loop invariant i <= N;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns b[0..N-1];
	*/
	for(i=0; i<N; i++)
	{
		if(i==0) {
			b[0] = 1;
		} else {
			b[i] = b[i-1] + a[i-1];
		}
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
