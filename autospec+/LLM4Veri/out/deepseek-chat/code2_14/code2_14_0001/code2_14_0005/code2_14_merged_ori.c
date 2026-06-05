/*@
  requires 0 <= x <= 2;
  requires 0 <= y <= 2;
*/
void foo(int x, int y) {
  int z1;
  int z2;
  int z3;
  /*@
  loop invariant z3 == 0;
  loop invariant z2 == 0;
  loop invariant z1 == 0;
  loop invariant y == 0 || y == 2 || y == 4;
  loop invariant y <= 4;
  loop invariant y < 4;
  loop invariant y % 2 == 0;
  loop invariant x == 0 || x == 2 || x == 4;
  loop invariant x <= 4;
  loop invariant x <= 4 || y <= 4;
  loop invariant x < 4;
  loop invariant x - y == \old(x) - \old(y);
  loop invariant x - 2 == y;
  loop invariant x + y == \old(x) + \old(y) + 4 * (x/2 - \old(x)/2);
  loop invariant x % 2 == 0;
  loop invariant \old(y) <= y;
  loop invariant \old(y) <= y || \old(x) <= x;
  loop invariant \old(y) < y;
  loop invariant \old(y) % 2 == y % 2;
  loop invariant \old(x) <= x;
  loop invariant \old(x) < x;
  loop invariant \old(x) < x;
  loop invariant \old(x) < x;
  loop invariant \old(x) < x;
  loop invariant \old(x) < x;
  loop invariant \old(x) < x;
  loop invariant \old(x) < x;
  loop invariant \old(x) % 2 == x % 2;
  loop invariant 0 <= y;
  loop invariant 0 <= y || y <= 4;
  loop invariant 0 <= y || x <= 4;
  loop invariant 0 <= x;
  loop invariant 0 <= x || y <= 4;
  loop invariant 0 <= x || x <= 4;
  loop invariant 0 <= x || 0 <= y;
  loop invariant 0 < y;
  loop invariant 0 < x;
  loop assigns y;
  loop assigns x;
  */
  while (unknown()) {
    x  = x + 2;
    y  = y + 2;
  }
  if (y == 0) {
    // @ assert x != 4;
  }
}