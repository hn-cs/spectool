#include <assert.h>
#define SIZE 10000000
int a[SIZE];
int i;
int main()
{
	/*@
	loop invariant i <= SIZE;
	loop invariant \forall integer j; 0 <= j < i ==> a[j] == 0;
	loop invariant 0 <= i;
	loop assigns a[0..SIZE-1];
	*/
	for(i=0;i<SIZE;i++)
	{
	a[i] = 0 ;
	}
	/*@
	loop invariant i <= SIZE/2;
	loop invariant \forall integer j; i <= j < SIZE/2 ==> a[j] == 0;
	loop invariant \forall integer j; 0 <= j < i ==> a[j] == 10;
	loop invariant 0 <= i;
	loop assigns a[0..SIZE/2-1];
	loop invariant i <= SIZE/2;
	loop invariant \forall integer j; i <= j < SIZE/2 ==> a[j] == 0;
	loop invariant \forall integer j; 0 <= j < i ==> a[j] == 10;
	loop invariant 0 <= i;
	loop assigns a[0..SIZE/2-1];
	*/
	for(i=0;i<SIZE/2;i++)
	{
	a[i] = 10 ;
	}
	/*@
	loop invariant i <= SIZE/2;
	loop invariant \forall integer j; i <= j < SIZE/2 ==> a[j] == 0;
	loop invariant \forall integer j; SIZE/2 <= j < SIZE ==> a[j] == 0;
	loop invariant \forall integer j; 0 <= j < i ==> a[j] == 10;
	loop invariant 0 <= i;
	loop assigns i;
	*/
	for(i=0;i<SIZE/2;i++)
	{
		// @ assert(a[i]==10);
	}
	return 0;
}	
