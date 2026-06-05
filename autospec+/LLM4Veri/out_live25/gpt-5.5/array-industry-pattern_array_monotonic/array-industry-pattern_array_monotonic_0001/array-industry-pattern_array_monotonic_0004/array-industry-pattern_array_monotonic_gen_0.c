#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define SIZE 100000
int main()
{
	int i;
	int a[SIZE];
	int b[SIZE];
	/*@
	loop invariant i/2 <= SIZE/2;
	loop invariant i <= SIZE;
	loop invariant i % 2 == 0;
	loop invariant \forall integer k; i <= k < SIZE ==> b[k] == \at(b[k],LoopEntry);
	loop invariant \forall integer k; i <= k < SIZE ==> a[k] == \at(a[k],LoopEntry);
	loop invariant \forall integer k; 0 <= k < i && k % 2 == 0 && b[k] != 20 ==> a[k] != 10;
	loop invariant \forall integer k; 0 <= k < i && k % 2 == 0 && a[k] == 10 ==> b[k] == 20;
	loop invariant \forall integer k; 0 <= k < SIZE && k % 2 != 0 ==> b[k] == \at(b[k],LoopEntry);
	loop invariant \forall integer k; 0 <= k < SIZE && k % 2 != 0 ==> a[k] == \at(a[k],LoopEntry);
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop invariant 0 <= i/2;
	loop assigns i;
	loop assigns b[0..SIZE-1];
	loop assigns a[0..SIZE-1];
	*/
	for(i = 0; i < SIZE;  i = i + 2)
	{
		a[i] = unknown();
		if(a[i] == 10)
			b[i] = 20;
	}
	/*@
	loop invariant 0 <= i <= SIZE;
	loop invariant i / 2 <= SIZE / 2;
	loop invariant 0 <= i / 2;
	loop invariant \forall integer k; 0 <= k < i && k % 2 == 0 && a[k] == 10 ==> b[k] == 20;
	loop invariant \forall integer k; i <= k < SIZE && k % 2 == 0 && a[k] == 10 ==> b[k] == 20;
	loop invariant \forall integer k; 0 <= k < SIZE ==> a[k] == \at(a[k],LoopEntry);
	loop invariant \forall integer k; 0 <= k < SIZE ==> b[k] == \at(b[k],LoopEntry);
	loop invariant i <= SIZE;
	loop invariant i % 2 == 0;
	loop invariant \forall integer k; 0 <= k < SIZE && k % 2 == 0 && a[k] == 10 ==> b[k] == 20;
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns i;
	*/
	for(i = 0; i < SIZE; i = i + 2)
	{
		if(a[i] == 10){
			// @ assert(b[i] == 20);
		}
	}
}
