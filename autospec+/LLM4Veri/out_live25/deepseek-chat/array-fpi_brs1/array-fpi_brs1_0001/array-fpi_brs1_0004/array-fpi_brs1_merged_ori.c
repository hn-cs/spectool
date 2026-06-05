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
	/*@
	loop invariant i == N;
	loop invariant i <= N;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] == 1 || a[k] == 0;
	loop invariant \forall integer k; 0 <= k < i && k % 1 == 0 ==> a[k] == 1;
	loop invariant \forall integer k; 0 <= k < i && k % 1 != 0 ==> a[k] == 0;
	loop invariant \forall integer k; 0 <= k < N && k % 1 == 0 ==> a[k] == 1;
	loop invariant \forall integer k; 0 <= k < N && k % 1 != 0 ==> a[k] == 0;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..N-1];
	*/
	for(i=0; i<N; i++)
	{
		if(i%1==0) {
			a[i] = 1;
		} else {
			a[i] = 0;
		}
	}
	/*@
	loop invariant i == N;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] == 1 || a[k] == 0;
	loop invariant \forall integer k; 0 <= k < N && k % 1 == 0 ==> a[k] == 1;
	loop invariant \forall integer k; 0 <= k < N && k % 1 != 0 ==> a[k] == 0;
	loop invariant i <= N;
	loop invariant \forall integer k; 0 <= k < i && k == 0 ==> sum[0] == 0;
	loop invariant \forall integer k; 0 <= k < i && k % 1 == 0 ==> a[k] == 1;
	loop invariant \forall integer k; 0 <= k < i && k % 1 != 0 ==> a[k] == 0;
	loop invariant \forall integer k; 0 < k < i ==> sum[0] == \sum_{j=1}^{k} a[j];
	loop invariant 0 <= i;
	loop assigns sum[0];
	loop assigns i;
	*/
	for(i=0; i<N; i++)
	{
		if(i==0) {
			sum[0] = 0;
		} else {
			sum[0] = sum[0] + a[i];
		}
	}
	// @ assert(sum[0] <= N);
	return 1;
}
