#include <assert.h>
#define SIZE 10000000
int a[SIZE];
int i;
int main()
{
	/*@
	loop invariant i <= SIZE;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] == 0;
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..SIZE-1];
	*/
	for(i=0;i<SIZE;i++)
	{
	a[i] = 0 ;
	}
	/*@
	loop invariant i <= SIZE/2;
	loop invariant \forall integer k; i <= k < SIZE ==> a[k] == 0;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] == 10;
	loop invariant SIZE/2 - i;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..SIZE/2-1];
	*/
	for(i=0;i<SIZE/2;i++)
	{
	a[i] = 10 ;
	}
	/*@
	loop invariant 0 <= i <= SIZE/2;
	loop invariant \forall integer k; 0 <= k < SIZE/2 ==> a[k] == 10;
	loop invariant \forall integer k; SIZE/2 <= k < SIZE ==> a[k] == 0;
	loop assigns i;
	loop variant SIZE/2 - i;
	*/
	for(i=0;i<SIZE/2;i++)
	{
		// @ assert(a[i]==10);
	}
	return 0;
}	
