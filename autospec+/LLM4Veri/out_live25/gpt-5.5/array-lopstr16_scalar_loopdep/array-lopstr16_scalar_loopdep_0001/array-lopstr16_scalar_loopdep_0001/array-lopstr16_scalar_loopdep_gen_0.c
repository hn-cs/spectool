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
	loop invariant 0 <= i <= SIZE;
	loop invariant y == 100 + i;
	loop invariant \forall integer k; 0 <= k < i ==> a[k].n == 100 + k;
	loop invariant \forall integer k; 0 <= k < i ==> a[k].n >= 100;
	loop assigns i;
	loop assigns x;
	loop assigns y;
	loop assigns a[0..SIZE-1].n;
	loop variant SIZE - i;
	*/
	for(i = 0; i < SIZE; i++)
	{
		x = y;
		a[i].n = y;
		y++;
	}
	for(i = 0; i < SIZE; i++)
	{
		// @ assert(a[i].n >= 100);
	}
	return 0;
}
