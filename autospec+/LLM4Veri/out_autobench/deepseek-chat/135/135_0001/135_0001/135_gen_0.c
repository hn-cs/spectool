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
	loop invariant 0 <= x;
	loop invariant 0 <= y;
	loop invariant 0 <= w;
	loop invariant w == 2 * (x + y);
	loop invariant z == 1 + (w/2) + y;
	loop invariant x <= y + 1;
	loop invariant (z - 1 - y) % 2 == 0;
	loop invariant x >= y;
	loop assigns i, j, z, x, y, w;
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
