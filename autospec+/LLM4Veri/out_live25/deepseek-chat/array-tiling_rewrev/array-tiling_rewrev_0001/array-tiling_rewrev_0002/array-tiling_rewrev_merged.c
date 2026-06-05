#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include<stdlib.h>
const int MAX = 100000;
int SIZE;
int main()
{
	SIZE = unknown();
	if(SIZE > 1 && SIZE < MAX)
	{
		int i;
		int *a = malloc(sizeof(int)*SIZE);
		int val2 = 3;
		int val1 = 7;
		int low=2;
		/*@
		loop invariant val2 == 3;
		loop invariant val1 == 7;
		loop invariant low == 2;
		loop invariant i <= SIZE-2;
		loop assigns i;
		loop assigns a[0..SIZE-1];
		*/
		for(i=SIZE-2; i >= -1; i--)
		{
			if(i >= 0)
			{
				a[i] = val1;
			}
			a[i+1] = val2;
		}
		/*@
		loop invariant i <= SIZE;
		loop invariant 0 <= i;
		loop assigns i;
		loop assigns a[0..SIZE-1];
		*/
		for(i = 0; i < SIZE; i++)
		{
			//@ assert(a[i] >= low);
		}
	}
	return 1;
}
