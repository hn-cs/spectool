#include<stdlib.h>
/*@
	assigns \nothing;
	ensures 1 < \result < 100000;
*/
int unknown();
long SIZE;
const int MAX = 100000;
int main()
{
	SIZE = unknown();
	if(SIZE > 1 && SIZE < MAX)
	{
		int i;
		long *a = malloc(sizeof(long)*SIZE);
		long sum=0;
		/*@
		loop invariant i <= SIZE;
		loop invariant \forall integer k; 0 <= k < i ==> a[k] == 1;
		loop invariant 0 <= i;
		loop assigns i;
		loop assigns a[0..SIZE-1];
		*/
		for(i = 0; i < SIZE; i++ )
		{
			a[i] = 1;
		}
		/*@
		loop invariant 0 <= i <= SIZE;
		loop invariant \forall integer k; 0 <= k < SIZE ==> a[k] == 1;
		loop invariant sum == i;
		loop assigns i;
		loop assigns sum;
		*/
		for(i = 0; i < SIZE; i++ )
		{
			sum = sum + a[i];
		}
		for(i = 0; i < SIZE; i++)
		{
			sum = sum - a[i];
		}
		for(i = 0; i < SIZE; i++ )
		{
			sum = sum + a[i];
		}
		for(i = 0; i < SIZE; i++)
		{
			sum = sum - a[i];
		}
		for(i = 0; i < SIZE; i++ )
		{
			sum = sum + a[i];
		}
		for(i = 0; i < SIZE; i++)
		{
			sum = sum - a[i];
		}
		for(i = 0; i < SIZE; i++ )
		{
			sum = sum + a[i];
		}
		for(i = 0; i < SIZE; i++)
		{
			sum = sum - a[i];
		}
		for(i = 0; i < SIZE; i++ )
		{
			sum = sum + a[i];
		}
		for(i = 0; i < SIZE; i++)
		{
			sum = sum - a[i];
		}
		// @ assert(sum == 0);
	}
	return 1;
}
