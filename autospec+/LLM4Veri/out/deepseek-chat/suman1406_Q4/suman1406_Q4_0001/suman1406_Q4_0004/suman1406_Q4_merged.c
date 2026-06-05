#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();
int main() {
  int w = 1;
  int z = 0;
  int x = 0;
  int y = 0;
  /*@
  loop invariant z == x + y;
  loop invariant w == x + y + 1;
  loop invariant z == y;
  loop invariant z % 2 == 0;
  loop invariant y % 2 == 0;
  loop invariant x == y;
  loop invariant x <= 1;
  loop invariant x % 2 == 0;
  loop invariant w == z + 1;
  loop invariant w == 1 + y + x;
  loop invariant w % 2 == 1;
  loop invariant \at(w + z, Pre) + (y + x) == w + z;
  loop invariant 0 <= x;
  loop assigns z;
  loop assigns y;
  loop assigns x;
  loop assigns w;
  */
  while (unknown2()) {
    if (w % 2 == 1) {
      x++;
      w++;
    }
    if (z % 2 == 0) {
      y++;
      z++;
    }
  }
  //@ assert x <= 1;
  return 0;
}