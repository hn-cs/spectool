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
	loop invariant \separated(a + (0..SIZE-1), b + (0..SIZE-1), c + (0..SIZE-1));
	loop invariant \forall integer j; 0 <= j < i ==> a[j].n + b[j].n == c[j].n;
	loop invariant \forall integer j; 0 <= j < i ==> \valid(&c[j]);
	loop invariant i <= SIZE;
	loop invariant \forall integer j; 0 <= j < i ==> \valid(&a[j]) && \valid(&b[j]);
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns b[0..SIZE-1];
	loop assigns a[0..SIZE-1];
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
	loop invariant \forall integer j; 0 <= j < i ==> c[j].n == a[j].n + b[j].n;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns c[0..SIZE-1];
	*/
	for(i = 0; i < SIZE; i++)
	{
		c[i].n = a[i].n + b[i].n;
	}
	/*@
	loop invariant i <= SIZE;
	loop invariant \forall integer j; 0 <= j < i ==> c[j].n == a[j].n + b[j].n;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns c[0..SIZE-1];
	*/
	for(i = 0; i < SIZE; i++)
	{
		// @ assert(c[i].n == a[i].n + b[i].n);
	}
	return 0;
}
