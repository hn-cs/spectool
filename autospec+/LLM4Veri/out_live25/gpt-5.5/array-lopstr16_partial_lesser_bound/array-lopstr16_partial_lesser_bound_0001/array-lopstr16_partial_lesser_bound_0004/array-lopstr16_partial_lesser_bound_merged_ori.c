#include<stdlib.h>
#include <assert.h>
#define SIZE 1000000
int *a[SIZE];
int i;
int main()
{
	/*@
	loop invariant i == 0 || a[i-1] == \null;
	loop invariant \valid(a + (0 .. SIZE-1));
	loop invariant \forall integer k; 0 <= k < SIZE ==> a[k] == \null;
	loop invariant SIZE == 1000000;
	loop invariant i <= SIZE;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] == \null;
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..SIZE-1];
	*/
	for(i = 0; i < SIZE; i++)
	{
		a[i] = 0;
	}
	/*@
	loop invariant i <= SIZE / 2;
	loop invariant \forall integer k; i <= k < SIZE ==> a[k] == \null;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] != \null;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..SIZE / 2 - 1];
	*/
	for(i = 0; i < SIZE / 2; i++)
	{
		a[i] = malloc(sizeof(int)) ;
	}
	/*@
	loop invariant i <= SIZE / 2;
	loop invariant \forall integer k; SIZE / 2 <= k < SIZE ==> a[k] == \null;
	loop invariant \forall integer k; 0 <= k < SIZE / 2 ==> a[k] != \null;
	loop invariant SIZE / 2 - i;
	loop invariant 0 <= i;
	loop assigns i;
	*/
	for(i = 0; i < SIZE / 2; i++)
	{
		// @ assert(a[i] != 0);
	}
	return 0;
}	
