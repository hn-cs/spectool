#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include<stdlib.h>
#include <assert.h>
#define SIZE 100000
struct S
{
	int *p;
	int n;
};
struct S *a[SIZE];
int main()
{
	int i;
	/*@
	loop invariant i <= SIZE;
	loop invariant \forall integer k; i <= k < SIZE ==> a[k] == \null;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] == \null || (\valid(a[k]) && a[k]->n == 0 && a[k]->p != \null);
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..SIZE-1];
	*/
	for (i = 0; i < SIZE; i++)
	{
		int q = unknown();
		struct S *s = 0;
		if (q == 0)
		{
			s = (struct S*) malloc(sizeof(struct S));
			s->n = q % 2;
		}
		if (s != 0)
		{
			if (s->n == 0)
			{
				s->p = (int *) malloc(sizeof(int));
			}
			else
			{
				s->p = 0;
			}
		}
		a[i] = s;
	}
	a[3] = (struct S*) malloc(sizeof(struct S));
	/*@
	loop invariant i <= SIZE;
	loop invariant \forall integer k; 0 <= k < SIZE && k != 3 ==> a[k] == \null || (\valid(a[k]) && a[k]->n == 0 && a[k]->p != \null);
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns i;
	*/
	for (i = 0; i < SIZE; i++)
	{
		struct S *s1 = a[i];
		if (i != 3 && s1 != 0 && s1->n == 0)
		{
			// @ assert(s1->p != 0);
		}
	}
	return 0;
}
