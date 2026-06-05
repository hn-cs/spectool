#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();


void main() {
  int x, y;

  x = -50;
  /*@
  loop invariant x >= -50;
  loop invariant x <= 0;
  loop invariant x + y >= -50;
  loop invariant y >= 1;
  loop invariant y <= -x + 1;
  loop assigns y;
  loop assigns x;
  */
  while( x < 0 ) {
	x = x + y;
	y++;
  }
  // @ assert(y > 0);
}

