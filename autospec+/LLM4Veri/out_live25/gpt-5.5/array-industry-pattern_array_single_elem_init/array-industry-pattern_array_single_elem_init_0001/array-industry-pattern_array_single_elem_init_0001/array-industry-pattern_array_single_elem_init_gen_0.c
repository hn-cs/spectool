#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define SIZE 100000
int unknown();
int main()
{
	int i;
	int a[SIZE];
	int b[SIZE];
	int c[SIZE];
	/*@
	loop invariant 0 <= i <= SIZE;
	loop invariant \forall integer k; 0 <= k < i ==> (a[k] == 0 || a[k] == 1);
	loop invariant \forall integer k; 0 <= k < i && a[k] != 0 ==> b[k] == k % 2;
	loop invariant \forall integer k; 0 <= k < i && a[k] != 0 ==> c[k] == k % 2;
	loop assigns i, a[0..SIZE-1], b[0..SIZE-1], c[0..SIZE-1];
	loop variant SIZE - i;
	*/
	for (i = 0; i < SIZE; i++)
	{
		int q = unknown();
		a[i] = 0;
		if (q == 0)
		{
			a[i] = 1;
			b[i] = i % 2;
		}
		if (a[i] != 0)
		{
			if (b[i] == 0)
			{
				c[i] = 0;
			}
			else
			{
				c[i] = 1;
			}
		}
	}
	a[15000] = 1;
	for (i = 0; i < SIZE; i++)
	{
		if (i == 15000 )
		{
			// @ assert(c[i] == 0);
		}
	}
	return 0;
}
