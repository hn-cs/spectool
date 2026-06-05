#include<assert.h>

int unknown1();
int unknown2();
int unknown3();
int unknown4();

/*@
requires (x + y) == k;
requires n > 0;
*/
void foo(int x, int y, int k, int j, int i, int n) {
  int m = 0;
  j = 0;
  /*@
  loop invariant x + y == k;
  loop invariant j <= n;
  loop invariant 0 <= j;
  loop invariant x + y == k;
  loop invariant j <= n;
  loop invariant \forall integer t; 0 <= t <= j && t == i ==> \old(y) - 1 == y;
  loop invariant \forall integer t; 0 <= t <= j && t == i ==> \old(x) + 1 == x;
  loop invariant 0 <= j;
  loop invariant (x + y) == k;
  loop assigns y;
  loop assigns x;
  loop assigns m;
  loop assigns j;
  */
  while (j < n) {
    if (j == i) {
      x++;
      y--;
    } else {
      y++;
      x--;
    }
    if (unknown1())
      m = j;
    j++;
  }
  // @ assert((x + y) == k);
  
  if (n > 0) {
    // @ assert(0 <= m);
    // @ assert(m < n);
  }

}