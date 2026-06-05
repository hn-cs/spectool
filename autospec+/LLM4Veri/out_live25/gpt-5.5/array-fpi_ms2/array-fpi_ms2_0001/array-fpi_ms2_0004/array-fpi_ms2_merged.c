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
	//@ assert (N <= 2147483647/4);
	int i;
	int sum[1];
	int *a = malloc(sizeof(int)*N);
	/*@
	loop invariant i <= N;
	loop invariant \forall integer k; 1 <= k < i ==> a[k] <= k;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] == k % 2;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] == 0 || a[k] == 1;
	loop invariant \forall integer k; 0 <= k < i ==> 0 <= a[k] <= 1;
	loop invariant \forall integer k; 0 <= k < i && k % 2 == 1 ==> a[k] == 1;
	loop invariant \forall integer k; 0 <= k < i && k % 2 == 0 ==> a[k] == 0;
	loop invariant N <= INT_MAX/4;
	loop invariant 0 <= i;
	loop invariant 0 < N;
	loop assigns i;
	loop assigns a[0..N-1];
	*/
	for(i=0; i<N; i++)
	{
		a[i] = i%2;
	}
	/*@
	loop invariant i > 0 ==> sum[0] == i / 2;
	loop invariant i > 0 ==> sum[0] <= N;
	loop invariant i > 0 ==> 0 <= sum[0] <= i;
	loop invariant \forall integer k; 0 <= k < N ==> a[k] == k % 2;
	loop invariant \forall integer k; 0 <= k < N && k % 2 == 1 ==> a[k] == 1;
	loop invariant \forall integer k; 0 <= k < N && k % 2 == 0 ==> a[k] == 0;
	loop invariant N <= INT_MAX/4;
	loop invariant 0 < N;
	loop invariant i <= N;
	loop invariant \forall integer k; 0 <= k < N ==> 0 <= a[k] <= 1;
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
	//@ assert(sum[0] <= N);
	return 1;
}
