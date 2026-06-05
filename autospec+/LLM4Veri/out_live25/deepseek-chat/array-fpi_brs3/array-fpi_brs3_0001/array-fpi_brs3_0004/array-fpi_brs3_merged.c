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
	long long sum[1];
	int *a = malloc(sizeof(int)*N);
	/*@
	loop invariant i == 0 ==> sum[0] == 0;
	loop invariant i <= N;
	loop invariant \forall integer k; 0 <= k < i ==> (k%3==0 ==> a[k] == 3) && (k%3!=0 ==> a[k] == 0);
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..N-1];
	*/
	for(i=0; i<N; i++)
	{
		if(i%3==0) {
			a[i] = 3;
		} else {
			a[i] = 0;
		}
	}
	/*@
	loop invariant sum[0] == \sum_{k=0}^{i-1} a[k] || i == 0;
	loop invariant sum[0] == \sum_{k=0}^{i-1} a[k] && 0 <= i <= N;
	loop invariant sum[0] == 0;
	loop invariant sum[0] == 0 && i == 0;
	loop invariant \forall integer k; 0 <= k<i ==> sum[0] == 0;
	loop invariant sum[0] == \sum_{k=0}^{i-1} a[k];
	loop invariant i <= N;
	loop invariant \forall integer k; 0 <= k < i ==> (k%3==0 ==> a[k] == 3) && (k%3!=0 ==> a[k] == 0);
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
	//@ assert(sum[0] <= 3*N);
	return 1;
}
