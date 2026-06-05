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
	loop invariant i <= SIZE;
	loop invariant \forall integer k; i <= k < SIZE ==> a[k] == \null;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] != \null;
	loop invariant \forall integer k; 0 <= k < i ==> \valid_read(a[k]);
	loop invariant \forall integer k; 0 <= k < i ==> \valid(a[k]);
	loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= a[k]->n < INT_MAX;
	loop invariant \forall integer k; 0 <= k < i ==> (a[k]->n == 0 || a[k]->p == \null);
	loop invariant \forall integer k; 0 <= k < i && a[k]->n == 0 ==> a[k]->p != \null;
	loop invariant \forall integer k; 0 <= k < i && a[k]->n == 0 ==> \valid_read(a[k]->p);
	loop invariant \forall integer k; 0 <= k < i && a[k]->n == 0 ==> \valid(a[k]->p);
	loop invariant \forall integer k; 0 <= k < i && a[k]->n != 0 ==> a[k]->p == \null;
	loop invariant \forall integer k, l; 0 <= k < l < i ==> \separated(a[k], a[l]);
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..SIZE-1];
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
	loop invariant \forall integer k; 0 <= k < SIZE ==> \valid_read(a[k]);
	loop invariant \forall integer k; 0 <= k < SIZE ==> INT_MIN <= a[k]->n < INT_MAX;
	loop invariant \forall integer k; 0 <= k < SIZE ==> (a[k]->n == 0 || a[k]->p == \null);
	loop invariant \forall integer k; 0 <= k < SIZE && a[k]->n == 0 ==> \valid_read(a[k]->p);
	loop invariant \forall integer k, l; 0 <= k < l < SIZE ==> \separated(a[k], a[l]);
	loop invariant \forall integer k; 0 <= k < i ==> a[k] != \null;
	loop invariant \forall integer k; i <= k < SIZE ==> a[k] != \null;
	loop invariant i <= SIZE;
	loop invariant \forall integer k; 0 <= k < SIZE ==> a[k] != \null;
	loop invariant \forall integer k; 0 <= k < SIZE ==> \valid(a[k]);
	loop invariant \forall integer k; 0 <= k < SIZE && a[k]->n == 0 ==> a[k]->p != \null;
	loop invariant \forall integer k; 0 <= k < SIZE && a[k]->n == 0 ==> \valid(a[k]->p);
	loop invariant \forall integer k; 0 <= k < SIZE && a[k]->n != 0 ==> a[k]->p == \null;
	loop invariant 0 <= i;
	loop assigns i;
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
