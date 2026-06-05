#include <assert.h>
#define SIZE 1000000
struct S
{
	int n;
};
struct S s[SIZE];
int main()
{
	int i;
	/*@
	loop invariant i > SIZE / 2 ==> i == SIZE / 2 + 1;
	loop invariant i <= SIZE;
	loop invariant i <= SIZE / 2 + 1;
	loop invariant \forall integer k; 0 <= k < i ==> s[k].n == 10;
	loop invariant \forall integer k; 0 <= k < i && k <= SIZE / 2 ==> s[k].n == 10;
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns s[0..SIZE/2].n;
	loop assigns i;
	*/
	for(i = 0; i < SIZE; i++)
	{
		if(i > SIZE / 2)
			break;
		s[i].n = 10;
	}
	/*@
	loop invariant i <= SIZE / 2 ==> \forall integer k; 0 <= k < i ==> s[k].n == 10;
	loop invariant i <= SIZE + 1;
	loop invariant \forall integer k; 0 <= k < i && k <= SIZE / 2 ==> s[k].n == 10;
	loop invariant \forall integer k; 0 <= k < SIZE && k <= SIZE / 2 ==> s[k].n == 10;
	loop invariant i <= SIZE;
	loop invariant \forall integer k; 0 <= k <= SIZE / 2 ==> s[k].n == 10;
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns i;
	*/
	for(i = 0; i < SIZE; i++)
	{
		if(i <= SIZE /2 ){
			// @ assert(s[i].n == 10);
		}
	}
	return 0;
}
