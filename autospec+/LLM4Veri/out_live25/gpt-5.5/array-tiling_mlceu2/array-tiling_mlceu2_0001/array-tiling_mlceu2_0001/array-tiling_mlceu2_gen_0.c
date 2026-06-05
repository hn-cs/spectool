#include<limits.h>
/*@
assigns \nothing;
ensures 1 < \result < 100000;
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
		/*@
		loop invariant 0 <= i <= SIZE;
		loop invariant SIZE < MAX;
		loop invariant MAX == 100000;
		loop invariant \forall integer k; 0 <= k < i ==> a[k] == 0;
		loop assigns i, a[0..SIZE-1];
		loop variant SIZE - i;
		*/
		for(i=0; i<SIZE; i++)
		{
			if( i>>16 > 250)
			{
				a[i] = 1;
			}
			else
			{
				a[i] = 0;
			}
		}
		for(i=0; i<SIZE; i++)
		{
			// @ assert(a[i] == 0);
		}
	}
	return 1;
}
