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
	  loop invariant i % 2 == 0;
	  loop invariant \forall integer j; 0 <= j < i && j % 2 == 0 ==> \valid(a[j]);
	  loop invariant \forall integer j; 0 <= j < i && j % 2 == 0 && a[j]->t == 10 ==> \valid(a[j]->p1);
	  loop assigns i, a[0 .. SIZE-1];
	  loop variant SIZE - i;
	*/
	for(i = 0; i < SIZE; i = i+2)
	{
		struct S* s = (struct S*) malloc(sizeof(struct S));
		//@ admit \valid(s);
		s->t = unknown();
		if (s->t == 10) {
			s->p1 = (int *) malloc(sizeof(int));
			//@ admit \valid(s->p1);
		}
		a[i] = s;
	}
	/*@
	  loop invariant 0 <= i <= SIZE;
	  loop invariant i % 2 == 0;
	  loop invariant \forall integer j; 0 <= j < SIZE && j % 2 == 0 ==> \valid(a[j]);
	  loop invariant \forall integer j; 0 <= j < SIZE && j % 2 == 0 && a[j]->t == 10 ==> \valid(a[j]->p1);
	  loop assigns i;
	  loop variant SIZE - i;
	*/
	for(i = 0; i < SIZE; i = i+2)
	{
		struct S* u = a[i];
		if (u->t == 10)
		{
			//@ assert(u->p1 != (void *) 0);
		}
	}
}
