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
		int *acopy = malloc(sizeof(int)*SIZE);
		/*@
		loop invariant i <= SIZE;
		loop invariant SIZE < MAX;
		loop invariant 1 < SIZE;
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
		loop invariant SIZE % 2 == 0;
		loop invariant 2 <= SIZE;
		loop invariant SIZE <= MAX - 1;
		loop invariant 0 <= i <= SIZE/2;
		loop invariant \forall integer k; 0 <= k < i ==> acopy[k] == a[k];
		loop invariant \forall integer k; 0 <= k < i ==> acopy[SIZE-k-1] == a[SIZE-k-1];
		loop invariant \forall integer k; 0 <= k < i ==> 0 <= k < SIZE;
		loop invariant \forall integer k; 0 <= k < i ==> i <= SIZE-k-1 < SIZE;
		loop invariant i <= SIZE/2;
		loop invariant \forall integer k; 0 <= k < i ==> 0 <= SIZE - k - 1 < SIZE;
		loop invariant 0 <= i;
		loop assigns i;
		loop assigns acopy[0..SIZE-1];
		*/
		for(i=0; i<SIZE/2; i++)
		{
			acopy[SIZE-i-1] = a[SIZE-i-1];
			acopy[i] = a[i];
		}
		/*@
		loop invariant i <= SIZE;
		loop invariant 0 <= i;
		loop assigns i;
		*/
		for(i=0; i<SIZE; i++)
		{
			// @ assert(acopy[i] == a[i]);
		}
	}
	return 1;
}
