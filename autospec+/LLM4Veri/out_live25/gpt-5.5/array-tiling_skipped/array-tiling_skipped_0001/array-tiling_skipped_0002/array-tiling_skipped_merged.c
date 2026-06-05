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
    /*@
    loop invariant i <= SIZE;
    loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= a[k] < INT_MAX;
    loop invariant 0 <= i;
    loop assigns i;
    loop assigns a[0..SIZE-1];
    */
    for(i = 0; i < SIZE; i++)
		{
		    a[i] = unknown();
		}
		if(SIZE % 2 != 0) { return 1; }
		// @ assert(SIZE % 2 == 0);
		/*@
		loop invariant i <= SIZE/2 + 1;
		loop invariant \forall integer k; 0 <= k < 2*i - 2 ==> a[k] <= k;
		loop invariant 1 <= i;
		loop assigns i;
		loop assigns a[0..SIZE-1];
		*/
		for(i = 1; i <= SIZE/2; i++ )
		{
			if( a[2*i-2] > 2*i-2 )
			{
				a[2*i-2] = 2*i-2;
			}
			if( a[2*i-1] > 2*i-1 )
			{
				a[2*i-1] = 2*i-1;
			}
		}
		for(i = 0; i < SIZE; i++)
		{
			// @ assert(a[i] <= i);
		}
	}
	return 1;
}
