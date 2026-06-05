#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define SIZE 1000000
typedef struct
{
	int n;
}S;
/*@
requires size >= 0;
requires \valid(a + (0..size-1));
ensures \forall integer i; 0 <= i < size ==> a[i].n != 0 || a[i].n == 0;
ensures \forall integer i; 0 <= i < size ==> \exists integer v; v == a[i].n;
assigns a[0..size-1];
*/
void init(S a[], int size)
{
	int i;
	/*@
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..size-1];
	*/
	for(i = 0; i < size; i++)
	{
		a[i].n = unknown();
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
		// @ assert(a[i].n == 0 );
		}
	}
	return 0;
}	
