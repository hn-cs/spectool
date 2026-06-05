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
	int *a = malloc(sizeof(int)*N);
	/*@
	loop invariant i <= N;
	loop invariant \forall integer j; 0 <= j < i ==> a[j] == 0;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..N-1];
	*/
	for (i = 0; i < N; i++)
	{
		a[i] = 0;
	}
	/*@
	loop invariant i <= N;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..N-1];
	*/
	for (i = 0; i < N; i++)
	{
		if (N%2 == 0) {
			a[i] = a[i] + 2;
		} else {
			a[i] = a[i] + 1;
		}
	}
	/*@
	loop invariant i <= N;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..N-1];
	*/
	for (i = 0; i < N; i++)
	{
		//@ assert(a[i] % 2 == N % 2);
	}
	return 1;
}
