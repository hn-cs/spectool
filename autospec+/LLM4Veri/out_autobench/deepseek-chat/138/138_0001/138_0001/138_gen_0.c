#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();

void main(int flag)
{

	int x = 0;
	int y = 0;

	int j = 0;
	int i = 0;

	/*@
	loop invariant x == y;
	loop invariant i == j;
	loop invariant 0 <= x;
	loop invariant 0 <= y;
	loop invariant 0 <= i;
	loop invariant 0 <= j;
	loop assigns x, y, i, j;
	loop variant 0;
	*/
	while(unknown1())
	{
	  x++;
	  y++;
	  i += x;
	  j += y;
	  if (flag)
	  	j+=1;
	} 
	// @ assert(j>=i);
	
}
