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
		long long sum=0;
		/*@
		loop invariant i <= SIZE;
		loop invariant \forall integer j; 0 <= j < i ==> a[j] == 1;
		loop invariant 0 <= i;
		loop assigns i;
		loop assigns a[0..SIZE-1];
		*/
		for(i = 0; i < SIZE; i++ )
		{
			a[i] = 1;
		}
		/*@
		loop invariant sum == i;
		loop invariant i <= SIZE;
		loop invariant \forall integer j; 0 <= j < SIZE ==> a[j] == 1;
		loop invariant 0 <= i;
		loop assigns sum;
		loop assigns i;
		*/
		for(i = 0; i < SIZE; i++ )
		{
			sum = sum + a[i];
		}
		/*@
		loop invariant sum == \at(sum, Pre) + i;
		loop invariant i <= SIZE;
		loop invariant 0 <= i;
		loop assigns sum;
		loop assigns i;
		*/
		for(i = 0; i < SIZE; i++ )
		{
			sum = sum + a[i];
		}
		/*@
		loop invariant sum == \at(sum, Pre) - i;
		loop invariant i <= SIZE;
		loop invariant \forall integer j; 0 <= j < SIZE ==> a[j] == 1;
		loop invariant 0 <= i;
		loop assigns sum;
		loop assigns i;
		*/
		for(i = 0; i < SIZE; i++)
		{
			sum = sum - a[i];
		}
		for(i = 0; i < SIZE; i++)
		{
			sum = sum - a[i];
		}
		// @ assert(sum == 0);
	}
	return 1;
}
