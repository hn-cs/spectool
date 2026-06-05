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
	loop invariant i <= SIZE;
	loop invariant i % 2 == 0;
	loop invariant \forall integer k; 0 <= k < i && k % 2 == 0 ==> a[k] != \null;
	loop invariant \forall integer k; 0 <= k < i && k % 2 == 0 && a[k]->t == 10 ==> a[k]->p1 != \null;
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..SIZE-1];
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
