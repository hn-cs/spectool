#include <assert.h>

int unknown1();
int unknown2();
int unknown3();
int unknown4();

void main() {
  int w = 1, z = 0, x = 0, y = 0;
  /*@
  loop invariant z == 0;
  loop invariant x == y;
  loop invariant w == 1;
  loop invariant 0 <= y;
  loop invariant 0 <= x;
  loop assigns z;
  loop assigns y;
  loop assigns x;
  loop assigns w;
  */
  while (unknown1()) {
    /*@
    loop invariant z == 0;
    loop invariant x == y;
    loop invariant w == 1;
    loop invariant 0 <= y;
    loop invariant 0 <= x;
    loop assigns y;
    loop assigns x;
    loop assigns z;
    loop assigns w;
    loop invariant z == 0;
    loop invariant x == y;
    loop invariant w == 1;
    loop invariant 0 <= y;
    loop invariant 0 <= x;
    loop assigns y;
    loop assigns x;
    */
    while (unknown2()) {
      if (w % 2 == 1)
        x++;
      if (z % 2 == 0)
        y++;
    }
    /*@
    loop invariant z == x + y;
    loop invariant y == \at(y, Pre);
    loop invariant x == \at(x, Pre);
    loop invariant w == z + 1;
    loop invariant w == x + y + 1;
    loop assigns z;
    loop assigns w;
    */
    while (unknown4()) {
      z = x + y;
      w = z + 1;
    }
  }
  // @ assert(x == y);
}