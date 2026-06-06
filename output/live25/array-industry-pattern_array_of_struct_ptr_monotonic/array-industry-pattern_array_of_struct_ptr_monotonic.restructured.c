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
	// Loop 1: allocate structs
	for(i = 0; i < SIZE; i = i+2)
	{
		a[i] = (struct S*) malloc(sizeof(struct S));
		//@ admit \valid(a[i]);
	}
	// Loop 2: initialize structs
	for(i = 0; i < SIZE; i = i+2)
	{
		a[i]->t = unknown();
		if (a[i]->t == 10) {
			a[i]->p1 = (int *) malloc(sizeof(int));
			//@ admit \valid(a[i]->p1);
		}
	}
	// Loop 3: verify
	for(i = 0; i < SIZE; i = i+2)
	{
		struct S* u = a[i];
		if (u->t == 10)
		{
			//@ assert(u->p1 != (void *) 0);
		}
	}
}
