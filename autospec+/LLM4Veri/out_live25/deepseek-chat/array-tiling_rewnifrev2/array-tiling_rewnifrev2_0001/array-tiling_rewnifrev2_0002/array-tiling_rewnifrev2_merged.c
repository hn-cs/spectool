#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include<stdlib.h>
int SIZE;
const int MAX = 100000;
int main()
{
	SIZE = unknown();
	int i;
	if(SIZE > 1 && SIZE < MAX)
	{
		int *a = malloc(sizeof(int)*SIZE);
		/*@
		loop invariant i+1 <= SIZE-1;
		loop invariant \forall integer k; i+1 < k < SIZE ==> a[k] >= k;
		loop invariant \forall integer k; i+1 < k < SIZE ==> a[k] == k;
		loop invariant 0 <= i+1;
		loop invariant -1 <= i;
		loop assigns i;
		loop assigns a[0..SIZE-1];
		*/
		for( i=SIZE-2; i >= 0; i-- )
		{
			a[i] = i;
			a[i+1] = i+1;
		}
		/*@
		loop invariant i <= SIZE;
		loop invariant 0 <= i;
		loop assigns i;
		loop assigns a[0..SIZE-1];
		*/
		for(i = 0; i < SIZE; i++)
		{
			//@ assert(a[i] >= i );
		}
	}
	return 1;
}
