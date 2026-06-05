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
	/*@
	loop invariant i <= N;
	loop invariant \forall integer j; 0 <= j < i ==> (j%2==0 ? a[j] == 2 : a[j] == 0);
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..N-1];
	*/
	for(i=0; i<N; i++)
	{
		if(i%2==0) {
			a[i] = 2;
		} else {
			a[i] = 0;
		}
	}
	/*@
	loop invariant 0 <= i <= N;
	loop invariant sum[0] == \sum(\lambda integer j; 0 < j < i, a[j]);
	loop invariant sum[0] <= 2 * (i-1);
	loop assigns i, sum[0];
	*/
	for(i=0; i<N; i++)
	{
		if(i==0) {
			sum[0] = 0;
		} else {
			sum[0] = sum[0] + a[i];
		}
	}
	// @ assert(sum[0] <= 2*N);
	return 1;
}
