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
	loop invariant x == y - 1;
	loop invariant \forall integer k; 0 <= k < i ==> a[k].n == 100 + k;
	loop assigns i, x, y, a[0..SIZE-1];
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
