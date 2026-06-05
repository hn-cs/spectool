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
	loop invariant 0 <= i <= SIZE;
	loop invariant \forall integer k; 0 <= k < i ==> a[k] != \null;
	loop invariant \forall integer k; 0 <= k < i ==> \valid(a[k]);
	loop invariant \forall integer k; 0 <= k < i ==> (a[k]->n == 1 ==> a[k]->p != \null);
	loop invariant \forall integer k; 0 <= k < i ==> (a[k]->n != 1 ==> a[k]->p == \null);
	loop assigns i, a[0..SIZE-1];
	loop variant SIZE - i;
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
