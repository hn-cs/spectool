#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();


void main() {
  int x, y;

  x = -50;
  /*@
  loop invariant x <= 0;
  loop invariant x + (y * (y-1)) / 2 == -50;
  loop invariant y >= 0;
  loop assigns x;
  loop assigns y;
  */
  while( x < 0 ) {
	x = x + y;
	y++;
  }
  // @ assert(y > 0);
}

