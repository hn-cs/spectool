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
		loop invariant \forall integer j; 0 <= j < i ==> a[j] == \at(a[j], Pre);
		loop invariant 0 <= i;
		loop assigns a[0..SIZE-1];
		*/
		for(i = 0; i < SIZE; i++)
		{
		    a[i] = unknown();
		}
		if(SIZE % 2 != 0) { return 1; }
		// @ assert(SIZE % 2 == 0);
		/*@
		loop invariant i <= SIZE/2;
		loop invariant \forall integer j; SIZE-i <= j < SIZE ==> acopy[j] == a[j];
		loop invariant \forall integer j; 0 <= j < i ==> acopy[j] == a[j];
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
		loop invariant 0 <= i <= SIZE;
		loop invariant \forall integer j; 0 <= j < i ==> acopy[j] == a[j];
		loop invariant \forall integer j; 0 <= j < i ==> acopy[SIZE-1-j] == a[SIZE-1-j];
		loop assigns i;
		*/
		for(i=0; i<SIZE; i++)
		{
			// @ assert(acopy[i] == a[i]);
		}
	}
	return 1;
}
