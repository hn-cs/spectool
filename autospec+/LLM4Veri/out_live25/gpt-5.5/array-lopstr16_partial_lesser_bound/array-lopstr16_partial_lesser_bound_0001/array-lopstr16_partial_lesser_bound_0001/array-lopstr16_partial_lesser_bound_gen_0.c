#include<stdlib.h>
#include <assert.h>
#define SIZE 1000000
int *a[SIZE];
int i;
int main()
{
	/*@
	loop invariant 0 <= i <= SIZE;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] == \null;
	loop assigns i, a[0..SIZE-1];
	loop variant SIZE - i;
	*/
	for(i = 0; i < SIZE; i++)
	{
		a[i] = 0;
	}
	for(i = 0; i < SIZE / 2; i++)
	{
		a[i] = malloc(sizeof(int)) ;
	}
	for(i = 0; i < SIZE / 2; i++)
	{
		// @ assert(a[i] != 0);
	}
	return 0;
}	
