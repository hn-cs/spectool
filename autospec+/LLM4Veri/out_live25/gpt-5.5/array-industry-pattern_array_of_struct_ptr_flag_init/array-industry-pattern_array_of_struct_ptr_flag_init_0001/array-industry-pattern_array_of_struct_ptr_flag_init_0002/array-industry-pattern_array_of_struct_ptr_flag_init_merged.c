#include<stdlib.h>
#include <assert.h>
#define SIZE 100000
typedef struct
{
	int *n;
}S;
/*@
requires size >= 0;
requires size == 0 || \valid(a + (0..size-1));
ensures \forall integer i; 0 <= i < size ==> a[i].n == \null || \valid(a[i].n);
assigns a[0..size-1].n;
*/
void init(S a[], int size)
{
	int i;
	/*@
	loop invariant 0 <= i;
	*/
	for(i = 0; i < size; i++)
	{
		a[i].n = (int *) malloc(sizeof(int));
	}
}
int main()
{
	S a[SIZE];
	int i;
	int flag;
	flag = 0;
	init(a, SIZE);
	for(i = 0; i < SIZE; i++)
	{
		if(a[i].n != 0)
		{
			flag = 1;
		}
	}
	for(i = 0; i < SIZE; i++)
	{
		if (flag == 0){
		// @ assert(a[i].n == 0);
		}
	}
	return 0;
}	
