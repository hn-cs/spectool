#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();

int main()
{
	int i = 1;
	int j = 0;
	int z = i - j;
	int x = 0;
	int y = 0;
	int w = 0;

	/*@
	loop invariant x == y;
	loop invariant z >= 0;
	loop invariant w >= 0;
	loop invariant z % 2 == 1 ==> x == y + 1;
	loop invariant z % 2 == 0 ==> x == y;
	loop invariant w == 2*y;
	loop invariant z == i - j + x + y + w;
	loop invariant x <= y + 1;
	loop invariant 0 <= y;
	loop invariant 0 <= x;
	loop invariant 0 <= w;
	loop assigns z;
	loop assigns y;
	loop assigns x;
	loop assigns w;
	loop assigns j;
	loop assigns i;
	*/
	while(unknown2()) 
	{
		z += x + y + w;
		y++;
		if (z % 2 == 1) 
		  x++;
		w += 2; 
	}

	// @ assert(x==y);
}
