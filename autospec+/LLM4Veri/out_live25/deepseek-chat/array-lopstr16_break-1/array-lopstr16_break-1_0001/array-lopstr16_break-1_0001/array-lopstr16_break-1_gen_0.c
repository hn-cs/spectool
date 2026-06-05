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
	loop invariant 0 <= i <= SIZE;
	loop invariant \forall integer j; 0 <= j < i ==> 
	    (c > 5 ==> s[j].n == \null) && 
	    (c <= 5 ==> s[j].n != \null);
	loop assigns i, s[0..SIZE-1].n;
	loop variant SIZE - i;
	*/
	for(i = 0; i < SIZE; i++)
	{
		if(c > 5)
			break;
		s[i].n = malloc(sizeof(int));
	}
	for(i = 0; i < SIZE; i++)
	{
		if(c <= 5){
			// @ assert(s[i].n != 0);
		}
	}
	return 0;
}
