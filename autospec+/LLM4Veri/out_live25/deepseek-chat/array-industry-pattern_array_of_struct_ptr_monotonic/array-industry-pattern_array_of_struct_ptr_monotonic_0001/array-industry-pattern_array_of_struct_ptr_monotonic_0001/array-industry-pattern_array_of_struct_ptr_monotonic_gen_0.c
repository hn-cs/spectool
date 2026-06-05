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
	int t;
	int * p1;
};
struct S* a[SIZE];
int main()
{
	int i;
	/*@
	loop invariant 0 <= i <= SIZE;
	loop invariant \forall integer k; 0 <= k < i && k % 2 == 0 ==> \valid(a[k]);
	loop invariant \forall integer k; 0 <= k < i && k % 2 == 0 ==> a[k]->t == unknown();
	loop invariant \forall integer k; 0 <= k < i && k % 2 == 0 && a[k]->t == 10 ==> \valid(a[k]->p1);
	loop assigns i, a[0..SIZE-1];
	loop variant SIZE - i;
	*/
	for(i = 0; i < SIZE; i = i+2)
	{
		struct S* s = (struct S*) malloc(sizeof(struct S));
		s->t = unknown();
		if (s->t == 10)
			s->p1 = (int *) malloc(sizeof(int));
		a[i] = s;
	}
	for(i = 0; i < SIZE; i = i+2)
	{
		struct S* u = a[i];
		if (u->t == 10)
		{
			// @ assert(u->p1 != (void *) 0);
		}
	}
}
