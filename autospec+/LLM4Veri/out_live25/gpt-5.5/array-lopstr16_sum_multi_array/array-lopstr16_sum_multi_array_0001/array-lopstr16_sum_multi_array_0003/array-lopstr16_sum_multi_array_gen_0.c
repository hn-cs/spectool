#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define SIZE 1000000
struct _S
{
	int n;
};
typedef struct _S S;
S a[SIZE];
S b[SIZE];
S c[SIZE];
int main()
{
	int i;
	/*@
	loop invariant i <= SIZE;
	loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= b[k].n < INT_MAX;
	loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= a[k].n < INT_MAX;
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns b[0..SIZE-1].n;
	loop assigns a[0..SIZE-1].n;
	*/
	for(i = 0; i < SIZE; i++)
	{
		int v;
	        v = unknown();
		a[i].n= v;
		v = unknown();
		b[i].n = v;
	}
	/*@
	loop invariant i <= SIZE;
	loop invariant \forall integer k; 0 <= k < i ==> c[k].n == a[k].n + b[k].n;
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns c[0..SIZE-1].n;
	*/
	for(i = 0; i < SIZE; i++)
	{
		c[i].n = a[i].n + b[i].n;
	}
	/*@
	loop invariant 0 <= i <= SIZE;
	loop invariant \forall integer k; 0 <= k < SIZE ==> c[k].n == a[k].n + b[k].n;
	loop assigns i;
	loop variant SIZE - i;
	*/
	for(i = 0; i < SIZE; i++)
	{
		// @ assert(c[i].n == a[i].n + b[i].n);
	}
	return 0;
}
