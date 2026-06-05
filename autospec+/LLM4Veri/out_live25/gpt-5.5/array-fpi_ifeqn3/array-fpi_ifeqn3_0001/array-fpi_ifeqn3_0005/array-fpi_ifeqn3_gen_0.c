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
	loop invariant i <= N;
	loop invariant \forall integer k; 1 <= k < i ==> a[k] == a[k-1] + 6;
	loop invariant \forall integer k; 0 <= k < i-1 ==> a[k] < a[k+1];
	loop invariant \forall integer k; 0 <= k < i ==> a[k] > 0;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] == 6 + 6*k;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] == 6 * (k + 1);
	loop invariant \forall integer k; 0 <= k < i ==> a[k] <= 6*N;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] % 6 == 0;
	loop invariant N <= INT_MAX/4;
	loop invariant 1 <= N;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..N-1];
	*/
	for(i=0; i<N; i++)
	{
		if(i==0) {
			a[0] = 6;
		} else {
			a[i] = a[i-1] + 6;
		}
	}
	/*@
	loop invariant N <= INT_MAX/4;
	loop invariant 1 <= N;
	loop invariant \forall integer k; 0 <= k < N ==> a[k] == 6 * (k + 1);
	loop invariant \forall integer k; 0 <= k < N ==> a[k] % 6 == 0;
	loop invariant \forall integer k; 0 <= k < i ==> b[k] == 3*k*k + 3*k + 1;
	loop invariant \forall integer k; 0 <= k < i ==> b[k] == 3*k*(k + 1) + 1;
	loop invariant \forall integer k; 0 <= k < i ==> b[k] > 0;
	loop invariant \forall integer k; 1 <= k < i ==> b[k] == b[k-1] + a[k-1];
	loop invariant \forall integer k; 1 <= k < i ==> b[k] == b[k-1] + 6*k;
	loop invariant \forall integer k; 0 <= k < i-1 ==> b[k] < b[k+1];
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
		// @ assert(b[i] == 3*i*i + 3*i + 1);
	}
	return 1;
}
