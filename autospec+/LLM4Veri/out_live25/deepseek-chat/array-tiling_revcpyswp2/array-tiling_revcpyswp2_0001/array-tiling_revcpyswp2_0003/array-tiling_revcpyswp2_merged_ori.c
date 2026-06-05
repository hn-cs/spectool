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
		int tmp;
		int *a = malloc(sizeof(int)*SIZE);
		int *b = malloc(sizeof(int)*SIZE);
		int *a_copy = malloc(sizeof(int)*SIZE);
		int *b_copy = malloc(sizeof(int)*SIZE);
		/*@
		loop invariant i <= SIZE;
		loop invariant \forall integer j; 0 <= j < i ==> b_copy[j] == \at(b_copy[j], Pre);
		loop invariant \forall integer j; 0 <= j < i ==> a_copy[j] == \at(a_copy[j], Pre);
		loop invariant 0 <= i;
		loop assigns i;
		loop assigns b_copy[0..SIZE-1];
		loop assigns a_copy[0..SIZE-1];
		*/
		for(i=0; i<SIZE; i++)
		{
			a_copy[i] = unknown();
			b_copy[i] = unknown();
		}
		/*@
		loop invariant i <= SIZE;
		loop invariant \forall integer j; 0 <= j < i ==> b[j] == b_copy[SIZE-j-1];
		loop invariant \forall integer j; 0 <= j < i ==> a[j] == a_copy[SIZE-j-1];
		loop invariant SIZE - i;
		loop invariant 0 <= i;
		loop assigns i;
		loop assigns b[0..SIZE-1];
		loop assigns a[0..SIZE-1];
		*/
		for(i=0; i<SIZE; i++)
		{
			a[i] = a_copy[SIZE-i-1];
			b[i] = b_copy[SIZE-i-1];
		}
		/*@
		loop invariant i <= SIZE;
		loop invariant \forall integer j; i <= j < SIZE ==> b[j] == b_copy[SIZE-j-1];
		loop invariant \forall integer j; i <= j < SIZE ==> a[j] == a_copy[SIZE-j-1];
		loop invariant \forall integer j; 0 <= j < i ==> b[j] == a_copy[SIZE-j-1];
		loop invariant \forall integer j; 0 <= j < i ==> a[j] == b_copy[SIZE-j-1];
		loop invariant 0 <= i;
		loop assigns tmp;
		loop assigns i;
		loop assigns b[0..SIZE-1];
		loop assigns a[0..SIZE-1];
		*/
		for(i=0; i<SIZE; i++)
		{
			tmp = a[i];
			a[i] = b[i];
			b[i] = tmp;
		}
		for(i=0; i<SIZE; i++)
		{
			tmp = a[i];
			a[i] = b[i];
			b[i] = tmp;
		}
		for(i=0; i<SIZE; i++)
		{
			// @ assert(a[i] == a_copy[SIZE-i-1]);
		}
	}
	return 1;
}
