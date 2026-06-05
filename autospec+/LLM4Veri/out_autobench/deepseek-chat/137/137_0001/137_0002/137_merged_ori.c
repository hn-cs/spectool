#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();


void main() {
  int x, y;

  x = -50;
  /*@
  loop invariant 0 <= y;
  loop invariant -50 <= x;
  loop invariant -50 + y*(y-1)/2 <= x;
  loop invariant -50 + (y*(y-1))/2 <= x;
  loop assigns y;
  loop assigns x;
  */
  while( x < 0 ) {
	x = x + y;
	y++;
  }
  // @ assert(y > 0);
}

