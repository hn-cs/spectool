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
  loop invariant x == w/2;
  loop invariant y == z/2;
  loop invariant x <= y + 1;
  loop invariant z == y * 2;
  loop invariant w == x * 2 + 1;
  loop invariant x >= 0 && y >= 0;
  loop invariant x == y;
  loop invariant w == z + 1;
  loop invariant 1 <= w;
  loop invariant 0 <= z;
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

  // @ assert(x <= 1);
  return 0;
}