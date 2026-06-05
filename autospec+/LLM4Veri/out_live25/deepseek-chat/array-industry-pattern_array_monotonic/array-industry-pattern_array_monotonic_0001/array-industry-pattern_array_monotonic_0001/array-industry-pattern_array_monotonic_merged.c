#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define SIZE 100000
int main()
{
	int i;
	int a[SIZE];
	int b[SIZE];
	/*@
	loop invariant i <= SIZE;
	loop invariant \forall integer j; 0 <= j < i && j % 2 == 0 ==> (a[j] != 10 || b[j] == 20);
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns b[0..SIZE-1];
	loop assigns a[0..SIZE-1];
	*/
	for(i = 0; i < SIZE;  i = i + 2)
	{
		a[i] = unknown();
		if(a[i] == 10)
			b[i] = 20;
	}
	for(i = 0; i < SIZE; i = i + 2)
	{
		if(a[i] == 10){
			// @ assert(b[i] == 20);
		}
	}
}
