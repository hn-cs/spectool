#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define SIZE 100000
struct S
{
	int n;
};
struct S s[SIZE];
int main()
{
	int i;
	int c;
	c = unknown();
	/*@
	loop invariant i == 0 || c <= 5;
	loop invariant c > 5 ==> \forall integer j; 0 <= j < i ==> \false;
	loop invariant c <= INT_MAX;
	loop invariant c <= 5 ==> i >= 0;
	loop invariant c < INT_MAX;
	loop invariant \forall integer j; i <= j < SIZE ==> s[j].n == \at(s[j].n,LoopEntry);
	loop invariant \forall integer j; 0 <= j < i ==> s[j].n == 10;
	loop invariant INT_MIN <= c;
	loop invariant INT_MIN <= c || c < INT_MAX;
	loop invariant INT_MIN < c;
	loop invariant i > 0 ==> c <= 5;
	loop invariant i <= SIZE;
	loop invariant c > 5 ==> i == 0;
	loop invariant c == \at(c,LoopEntry);
	loop invariant c <= 5 ==> \forall integer j; 0 <= j < i ==> s[j].n == 10;
	loop invariant \forall integer j; 0 <= j < i ==> c <= 5 && s[j].n == 10;
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns s[0..SIZE-1];
	loop assigns i;
	*/
	for(i = 0; i < SIZE; i++)
	{
		if(c > 5)
			break;
		s[i].n = 10;
	}
	/*@
	loop invariant i <= SIZE;
	loop invariant c > 5 || \forall integer j; 0 <= j < SIZE ==> s[j].n == 10;
	loop invariant c == \at(c, LoopEntry);
	loop invariant c <= 5 ==> \forall integer j; 0 <= j < i ==> s[j].n == 10;
	loop invariant c <= 5 ==> \forall integer j; 0 <= j < SIZE ==> s[j].n == 10;
	loop invariant c <= 5 && i < SIZE ==> s[i].n == 10;
	loop invariant \forall integer j; 0 <= j < SIZE ==> s[j].n == \at(s[j].n, LoopEntry);
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns i;
	*/
	for(i = 0; i < SIZE; i++)
	{
		if(c <= 5){
			// @ assert(s[i].n == 10);
		}
	}
	return 0;
}
