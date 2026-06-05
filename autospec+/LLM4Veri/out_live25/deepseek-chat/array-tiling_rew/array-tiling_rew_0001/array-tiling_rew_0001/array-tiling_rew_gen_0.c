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
	if(SIZE > 1 && SIZE < MAX)
	{
		int i;
		int *a = malloc(sizeof(int)*SIZE);
		int val2 = 3;
		int val1 = 0;
		int low=2;
		/*@
		loop invariant 0 <= i <= SIZE;
		loop invariant \forall integer j; 0 <= j < i ==> a[j] == val2;
		loop invariant \forall integer j; 1 <= j < i+1 && j < SIZE ==> a[j] == val1;
		loop invariant val2 == 3;
		loop invariant val1 == 0;
		loop invariant low == 2;
		loop assigns i, a[0..SIZE-1];
		*/
		for(i = 0; i < SIZE; i++)
		{
			if(i+1 < SIZE)
			{
				a[i+1] = val1;
			}
			a[i] = val2;
		}
		for(i = 0; i < SIZE; i++)
		{
			// @ assert(a[i] >= low);
		}
	}
	return 1;
}
