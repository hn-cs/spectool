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
	loop invariant i == 0 || c <= 5;
	loop invariant c > 5 ==> i <= 0;
	loop invariant c <= 5 || i == 0;
	loop invariant c <= 5 ==> \forall integer k; 0 <= k < i ==> \valid(s[k].n);
	loop invariant c <= 5 ==> \forall integer k, l; 0 <= k < l < i ==> \separated(s[k].n, s[l].n);
	loop invariant c <= 5 ==> 0 <= i <= SIZE;
	loop invariant i > 0 ==> c <= 5;
	loop invariant i <= SIZE;
	loop invariant c > 5 ==> i == 0;
	loop invariant c > 5 ==> \forall integer k; 0 <= k < SIZE ==> s[k].n == \at(s[k].n, LoopEntry);
	loop invariant c == \at(c, LoopEntry);
	loop invariant c <= 5 ==> \forall integer k; 0 <= k < i ==> s[k].n != \null;
	loop invariant \forall integer k; i <= k < SIZE ==> s[k].n == \at(s[k].n, LoopEntry);
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns s[0..SIZE-1].n;
	loop assigns i;
	*/
	for(i = 0; i < SIZE; i++)
	{
		if(c > 5)
			break;
		s[i].n = malloc(sizeof(int));
	}
	/*@
	loop invariant i <= SIZE;
	loop invariant c > 5 ==> i >= 0;
	loop invariant c == \at(c, LoopEntry);
	loop invariant c <= 5 || c > 5;
	loop invariant c <= 5 ==> \forall integer k; 0 <= k < SIZE ==> s[k].n != \null;
	loop invariant \forall integer k; 0 <= k < SIZE ==> s[k].n == \at(s[k].n, LoopEntry);
	loop invariant SIZE - i;
	loop invariant 0 <= i;
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
