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
  loop invariant x >= 0 && y >= 0;
  loop invariant w >= 1;
  loop invariant z >= 0;
  loop invariant x <= 1;
  loop invariant x == y;
  loop invariant w == z + 1;
  loop assigns x, y, w, z;
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