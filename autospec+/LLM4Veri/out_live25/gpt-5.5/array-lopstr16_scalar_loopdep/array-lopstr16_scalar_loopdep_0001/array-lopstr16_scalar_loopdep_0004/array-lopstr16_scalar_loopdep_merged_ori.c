#include <assert.h>
#define SIZE 100000
struct _S
{
	int n;
};
typedef struct _S S;
S a[SIZE];
int main()
{
	int i,x;
	int y = 100;
	/*@
	loop invariant y == 100 + i;
	loop invariant y <= 100 + SIZE;
	loop invariant i > 0 ==> x == y - 1;
	loop invariant i > 0 ==> a[i-1].n == y - 1;
	loop invariant i > 0 ==> \exists integer k; 0 <= k < i && a[k].n == x;
	loop invariant i == y - 100;
	loop invariant i <= SIZE;
	loop invariant \forall integer k; 0 <= k < i ==> a[k].n >= 100;
	loop invariant \forall integer k; 0 <= k < i ==> a[k].n == 100 + k;
	loop invariant \forall integer k; 0 <= k < i ==> a[k].n <= y - 1;
	loop invariant \forall integer k; 0 <= k < i ==> a[k].n < y;
	loop invariant SIZE - i;
	loop invariant 100 <= y;
	loop invariant 0 <= i;
	loop assigns y;
	loop assigns x;
	loop assigns i;
	loop assigns a[0..SIZE-1].n;
	*/
	for(i = 0; i < SIZE; i++)
	{
		x = y;
		a[i].n = y;
		y++;
	}
	/*@
	loop invariant y == 100 + SIZE;
	loop invariant x == 100 + SIZE - 1;
	loop invariant i < SIZE ==> a[i].n == 100 + i;
	loop invariant \forall integer k; i <= k < SIZE ==> a[k].n == 100 + k;
	loop invariant \forall integer k; 0 <= k < i ==> a[k].n == 100 + k;
	loop invariant \forall integer k; 0 <= k < i ==> a[k].n < y;
	loop invariant \forall integer k; 0 <= k < SIZE ==> a[k].n <= x;
	loop invariant i <= SIZE;
	loop invariant \forall integer k; 0 <= k < SIZE ==> a[k].n >= 100;
	loop invariant \forall integer k; 0 <= k < SIZE ==> a[k].n == 100 + k;
	loop invariant SIZE - i;
	loop invariant 0 <= i;
	loop assigns i;
	*/
	for(i = 0; i < SIZE; i++)
	{
		// @ assert(a[i].n >= 100);
	}
	return 0;
}
