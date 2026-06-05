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
ensures \result == 1 || \result == 0;
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
	loop invariant \forall integer j; 0 <= j < i ==> a[j]->n == 1 || a[j]->n != 1;
	loop invariant \forall integer j; 0 <= j < i ==> a[j]->n == 1 <==> \valid(a[j]->p);
	loop invariant \forall integer j; 0 <= j < i ==> \valid(a[j]->p + (0..0)) || a[j]->n != 1;
	loop invariant \forall integer j; 0 <= j < i ==> (a[j]->n == 1 ==> a[j]->p != \null);
	loop invariant \forall integer j; 0 <= j < i ==> (a[j]->n == 1 ==> \separated(a[j]->p, a + (0..SIZE-1)));
	loop invariant \forall integer j; 0 <= j < i ==> (a[j]->n == 1 ==> \separated(a[j]->p, \null));
	loop invariant i <= SIZE;
	loop invariant \forall integer j; 0 <= j < i ==> \valid(a[j]);
	loop invariant \forall integer j; 0 <= j < i ==> (a[j]->n == 1 ==> \valid(a[j]->p));
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
	loop invariant \forall integer j; 0 <= j < i ==> a[j]->n == 1 ==> \valid(a[j]->p);
	loop invariant \forall integer j; 0 <= j < i ==> \valid(a[j]);
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns \nothing;
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
