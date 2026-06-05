#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include<stdlib.h>
#include <assert.h>
#define SIZE 100000
struct _S
{
	int *p;
	int n;
};
typedef struct _S S;
S *a[SIZE];
/*@
ensures INT_MIN <= \result < INT_MAX;
assigns \nothing;
*/
int user_read()
{
	int x = unknown();
	return x;
}
int main()
{
	int i;
	/*@
	loop invariant \valid(a + (0..SIZE-1));
	loop invariant \forall integer k; i <= k < SIZE ==> a[k] == \null;
	loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= a[k]->n < INT_MAX;
	loop invariant \forall integer k; 0 <= k < i && a[k]->n == 1 ==> \valid(a[k]->p);
	loop invariant \forall integer k; 0 <= k < i && a[k]->n != 1 ==> !\valid(a[k]->p);
	loop invariant \forall integer k, l; 0 <= k < l < i ==> \separated(a[k], a[l]);
	loop invariant i <= SIZE;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] != \null;
	loop invariant \forall integer k; 0 <= k < i ==> \valid(a[k]);
	loop invariant \forall integer k; 0 <= k < i ==> (a[k]->n == 1 ==> a[k]->p != \null);
	loop invariant \forall integer k; 0 <= k < i ==> (a[k]->n != 1 ==> a[k]->p == \null);
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..SIZE-1];
	*/
	for(i = 0; i < SIZE; i++)
	{
		S *s1 =  (S *)malloc(sizeof(S));
		s1 -> n = user_read();
		if(s1 ->n == 1)
		{
			s1 -> p = (int *)malloc(sizeof(int));
		}
		else
		{
			s1 -> p = (void *)0;
		}
		a[i] = s1;
	}
	/*@
	loop invariant i <= SIZE;
	loop invariant \forall integer k; 0 <= k < SIZE ==> a[k] != \null;
	loop invariant \forall integer k; 0 <= k < SIZE ==> \valid(a[k]);
	loop invariant \forall integer k; 0 <= k < SIZE ==> (a[k]->n == 1 ==> a[k]->p != \null);
	loop invariant \forall integer k; 0 <= k < SIZE ==> (a[k]->n != 1 ==> a[k]->p == \null);
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns i;
	*/
	for(i = 0; i < SIZE; i++)
	{
		S *s2 = a[i];
		if(s2 ->n == 1)
		{
			//@assert(s2 -> p != (void *)0);
		}
	}
	return 0;
}
