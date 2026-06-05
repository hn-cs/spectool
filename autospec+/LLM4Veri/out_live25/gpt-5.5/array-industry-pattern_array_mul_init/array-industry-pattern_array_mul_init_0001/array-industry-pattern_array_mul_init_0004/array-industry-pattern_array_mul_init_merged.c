#include <assert.h>
#include <limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#define SIZE 100000
int main()
{
	int a[SIZE];
	int b[SIZE];
	int k;
	int i;
	/*@
	loop invariant \forall integer j; 0 <= j < i ==> a[j] == b[j];
	loop invariant \forall integer j; 0 <= j < i ==> 0 <= b[j] < SIZE;
	loop invariant \forall integer j; 0 <= j < i ==> 0 <= a[j] < SIZE;
	loop invariant \forall integer j, k; 0 <= j < k < i ==> b[j] < b[k];
	loop invariant \forall integer j, k; 0 <= j < k < i ==> a[j] < a[k];
	loop invariant i <= SIZE;
	loop invariant \forall integer j; 0 <= j < i ==> b[j] == j;
	loop invariant \forall integer j; 0 <= j < i ==> a[j] == j;
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns b[0..SIZE-1];
	loop assigns a[0..SIZE-1];
	*/
	for (i  = 0; i<SIZE ; i++)
	{
		a[i] = i; 
		b[i] = i ;
	}
	/*@
	loop invariant i <= SIZE;
	loop invariant \forall integer j; i <= j < SIZE ==> a[j] == j && b[j] == j;
	loop invariant \forall integer j; 0 <= j < i ==> (a[j] == b[j] || b[j] == a[j] * a[j]);
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns k;
	loop assigns i;
	loop assigns b[0..SIZE-1];
	loop assigns a[0..SIZE-1];
	*/
	for (i=0; i< SIZE; i++)
	{
		if(unknown())
		{
			k = unknown();
			a[i] = k;
			b[i] = k * k ;
		}
	}
	/*@
	loop invariant i <= SIZE;
	loop invariant \forall integer j; 0 <= j < SIZE ==> (a[j] == b[j] || b[j] == a[j] * a[j]);
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns i;
	*/
	for (i=0; i< SIZE; i++)
	{
		// @ assert(a[i] == b[i] || b[i]  == a[i] * a[i]);
	}
}
