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
	loop invariant \forall integer j; 0 <= j < i ==> a[j] == 2*(j+1);
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..N-1];
	*/
	for(i=0; i<N; i++)
	{
		if(i==0) {
			a[0] = 2;
		} else {
			a[i] = a[i-1] + 2;
		}
	}
	/*@
	loop invariant i == 0 ==> b[i] == 1;
	loop invariant \forall integer j; 1 <= j < i ==> b[j] - b[j-1] == a[j-1];
	loop invariant \forall integer j; 0 <= j < i ==> b[j] == j*j + j + 1;
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
		// @ assert(b[i] == i*i + i + 1);
	}
	return 1;
}
