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
	int p;
	int n;
};
struct S a[SIZE];
int main()
{
	int i;
	/*@
	loop invariant \forall integer k; 0 <= k < i ==> a[k].p != 30;
	loop invariant \forall integer k; 0 <= k < i ==> (a[k].p == 20 ==> a[k].n != 0);
	loop invariant \forall integer k; 0 <= k < i ==> (a[k].p == 10 || a[k].p == 20);
	loop invariant \forall integer k; 0 <= k < i ==> (a[k].p == 10 ==> a[k].n == 0);
	loop invariant \forall integer k; 0 <= k < i ==> (a[k].n == 0 || a[k].n != 0);
	loop invariant i <= SIZE;
	loop invariant \forall integer k; 0 <= k < i ==> (a[k].n == 0 ==> a[k].p == 10);
	loop invariant \forall integer k; 0 <= k < i ==> (a[k].n != 0 ==> a[k].p == 20);
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns i;
	loop assigns a[0..SIZE-1];
	*/
	for (i = 0; i < SIZE; i++)
	{
		int q = unknown();
		struct S s;
	  s.n = unknown();
		if (s.n == 0)
		{
		    s.p =10 ;
		}
		else
		{
	 		s.p = 20;
		}
		a[i] = s;
	}
	a[3].p = 30;
	a[3].n = 40;
	/*@
	loop invariant i <= SIZE;
	loop invariant \forall integer k; 0 <= k < SIZE && k != 3 ==> (a[k].n == 0 ==> a[k].p == 10);
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns i;
	*/
	for (i = 0; i < SIZE; i++)
	{
		struct S s1 = a[i];
		if (i != 3 && s1.n == 0)
		{
			// @ assert(s1.p == 10); 
		}
	}
	return 0;
}
