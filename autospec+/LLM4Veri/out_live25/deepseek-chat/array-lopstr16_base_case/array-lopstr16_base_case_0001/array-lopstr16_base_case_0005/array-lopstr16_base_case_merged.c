#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include<stdlib.h>
#include <assert.h>
#define SIZE 1000000
struct S
{
	int n;
	int *p;
};
struct S *a[SIZE];
int main()
{
	int i;
	/*@
	loop invariant i == \at(i, LoopEntry) + (i - \at(i, LoopEntry));
	loop invariant \forall integer k; 0 <= k < i ==> \valid(a[k]->p) || a[k]->p == \null;
	loop invariant \forall integer k; 0 <= k < i ==> \valid(a[k]);
	loop invariant \forall integer k; 0 <= k < i ==> \separated(a[k]);
	loop invariant \forall integer k; 0 <= k < i ==> (a[k]->n == 0 <==> \valid(a[k]->p));
	loop invariant \forall integer k1, k2; 0 <= k1 < k2 < i ==> \separated(a[k1], a[k2]);
	loop invariant i <= SIZE;
	loop invariant \forall integer j; 0 <= j < i ==> a[j]->n == \at(unknown(), Pre);
	loop invariant \forall integer j; 0 <= j < i ==> \valid(a[j]);
	loop invariant \forall integer j; 0 <= j < i ==> (a[j]->n == 0 ==> \valid(a[j]->p));
	loop invariant \forall integer j; 0 <= j < i ==> (a[j]->n == 0 ==> \valid(a[j]->p + (0..0)));
	loop invariant \forall integer j; 0 <= j < i ==> (a[j]->n != 0 ==> a[j]->p == 0);
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..SIZE-1];
	loop assigns ((struct S*)a[0..SIZE-1])->p;
	loop assigns ((struct S*)a[0..SIZE-1])->n;
	*/
	for (i = 0; i < SIZE; i++)
	{
		struct S *s1 = (struct S *) malloc(sizeof(struct S));
		s1->n = unknown();
		if (s1->n == 0)
		{
			s1->p = (int *) malloc(sizeof(int));
		}
		else
		{
			s1->p = 0;
		}
		a[i] = s1;
	}
	/*@
	loop invariant i <= SIZE;
	loop invariant \forall integer j; 0 <= j < i ==> s2->n == \at(s2->n, Pre);
	loop invariant \forall integer j; 0 <= j < i ==> \valid(s2);
	loop invariant \forall integer j; 0 <= j < i ==> \valid(a[j]);
	loop invariant \forall integer j; 0 <= j < i ==> (s2->n == 0 ==> s2->p != 0);
	loop invariant \forall integer j; 0 <= j < i ==> (s2->n == 0 ==> \valid(s2->p));
	loop invariant \forall integer j; 0 <= j < i ==> (s2->n != 0 ==> s2->p == 0);
	loop invariant \forall integer j; 0 <= j < i ==> (a[j]->n == 0 ==> \valid(a[j]->p));
	loop invariant \forall integer j; 0 <= j < i ==> (a[j]->n != 0 ==> a[j]->p == 0);
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..SIZE-1];
	*/
	for (i = 0; i < SIZE; i++)
	{
		struct S *s2 = a[i];
		if (s2->n == 0)
		{
			// @ assert(s2->p != 0);
		}
	}
	return 0;
}
