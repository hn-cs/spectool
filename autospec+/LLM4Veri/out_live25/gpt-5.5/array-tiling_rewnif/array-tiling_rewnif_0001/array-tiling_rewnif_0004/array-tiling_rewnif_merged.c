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
		loop invariant i == 0 || a[i-1] == i-1;
		loop invariant i <= SIZE;
		loop invariant i < SIZE + 1;
		loop invariant \forall integer k; 0 <= k < i ==> a[k] == k;
		loop invariant \forall integer k; 0 < k <= i && k < SIZE ==> (a[k] == k || a[k] == k - 1);
		loop invariant SIZE < MAX;
		loop invariant 1 < SIZE;
		loop invariant 0 <= i;
		loop invariant 0 < i < SIZE ==> a[i] == i - 1;
		loop assigns i;
		loop assigns a[0..SIZE-1];
		*/
		for( i = 0; i < SIZE ; i++ )
		{
			if((i+1) < SIZE )
			{
				a[i+1] = i;
			}
			a[i] = i;
		}
		/*@
		loop invariant i > 0 ==> \exists integer k; 0 <= k < i && a[k] == k;
		loop invariant i == 0 || a[i-1] == i-1;
		loop invariant i < SIZE + 1;
		loop invariant \forall integer k; i <= k < SIZE ==> a[k] == k;
		loop invariant \forall integer k; 0 <= k < i ==> a[k] == k;
		loop invariant \forall integer k; 0 <= k < SIZE ==> a[k] >= 0;
		loop invariant \forall integer k; 0 <= k < SIZE ==> a[k] <= SIZE - 1;
		loop invariant SIZE < MAX;
		loop invariant 1 < SIZE;
		loop invariant i <= SIZE;
		loop invariant \forall integer k; 0 <= k < i ==> a[k] >= k;
		loop invariant \forall integer k; 0 <= k < SIZE ==> a[k] == k;
		loop invariant 0 <= i;
		loop assigns i;
		loop assigns \nothing;
		*/
		for(i = 0; i < SIZE; i++)
		{
			//@ assert(a[i] >= i );
		}
	}
	return 1;
}
