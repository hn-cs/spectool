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
	int *n;
};
struct S s[SIZE];
int main()
{
	int i;
	int c=unknown();
	/*@
	loop invariant \forall integer j; 0 <= j < i ==> s[j].n != \null;
	loop invariant \forall integer j; i <= j < SIZE ==> s[j].n == \null;
	loop invariant c > 5 || i == SIZE;
	loop invariant c <= 5 || i == 0;
	loop invariant i <= SIZE;
	loop invariant \forall integer j; 0 <= j < i == >;
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop invariant (c > 5) ==> i == 0;
	loop invariant (c > 5) ==> \forall integer j; 0 <= j < SIZE ==> s[j].n == \null;
	loop invariant (c <= 5) ==> i <= SIZE;
	loop invariant (c <= 5) ==> \forall integer j; 0 <= j < i ==> s[j].n != \null;
	loop assigns s[0..SIZE-1].n;
	loop assigns i;
	(c > 5 ==> s[j].n == \null) &&;
	(c <= 5 ==> s[j].n != \null);
	*/
	for(i = 0; i < SIZE; i++)
	{
		if(c > 5)
			break;
		s[i].n = malloc(sizeof(int));
	}
	/*@
	loop invariant i <= SIZE;
	loop invariant 0 <= i;
	loop invariant (c > 5) ==> i == 0;
	loop invariant (c > 5) ==> \forall integer j; 0 <= j < SIZE ==> s[j].n == \null;
	loop invariant (c <= 5) ==> \forall integer j; i <= j < SIZE ==> s[j].n == \null;
	loop invariant (c <= 5) ==> \forall integer j; 0 <= j < i ==> s[j].n != \null;
	loop assigns s[0..SIZE-1].n;
	loop assigns i;
	*/
	for(i = 0; i < SIZE; i++)
	{
		if(c <= 5){
			// @ assert(s[i].n != 0);
		}
	}
	return 0;
}
