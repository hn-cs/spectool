#include<stdlib.h>
#include <assert.h>
#define SIZE 100000
int *a[SIZE];
int i;
int main ()
{
	/*@
	loop invariant i <= SIZE;
	loop invariant \forall integer j; 0 <= j < i ==> a[j] == (void*)0;
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
	loop invariant \forall integer j; i <= j < SIZE / 2 ==> a[j] == \null;
	loop invariant \forall integer j; SIZE / 2 <= j < SIZE ==> a[j] == \null;
	loop invariant \forall integer j; 0 <= j < i ==> a[j] != \null;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..SIZE/2 - 1];
	*/
	for(i = 0; i < SIZE / 2; i++)
	{
		a[i] = malloc(sizeof(int)) ;
	}
	/*@
	loop invariant 0 <= i <= SIZE / 2;
	loop invariant \forall integer j; 0 <= j < i ==> a[j] == \null;
	loop invariant \forall integer j; i <= j < SIZE / 2 ==> a[j] != \null;
	loop invariant \forall integer j; SIZE / 2 <= j < SIZE ==> a[j] == (void*)0;
	loop assigns i;
	loop assigns a[0..SIZE/2 - 1];
	*/
	for(i = 0; i < SIZE / 2; i++)
	{
		// @ assert(a[i] != 0);
	}
return 0;
}	
