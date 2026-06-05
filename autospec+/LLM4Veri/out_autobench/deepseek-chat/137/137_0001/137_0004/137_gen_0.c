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
  loop invariant y <= -x + 1 || 1 <= y;
  loop invariant -50 <= x;
  loop invariant y <= -x + 1 || -50 <= x + y;
  loop invariant y <= -x + 1 || 1 <= y;
  loop invariant y <= -x + 1 || -50 <= x + y;
  loop invariant x <= 0 || 1 <= y;
  loop invariant x <= 0 || -50 <= x + y;
  loop invariant -50 <= x || x <= 0;
  loop assigns y;
  loop assigns x;
  */
  while( x < 0 ) {
	x = x + y;
	y++;
  }
  // @ assert(y > 0);
}

