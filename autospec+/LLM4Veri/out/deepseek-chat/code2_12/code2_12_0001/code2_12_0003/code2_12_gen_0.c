/*@
  requires 0 <= x <= 10;
  requires 0 <= y <= 10;
*/
void foo(int x, int y) {
  int z1;
  int z2;
  int z3;
  /*@
  loop invariant y - x == 0;
  loop invariant x % 10 == 0;
  loop invariant y % 10 == 0;
  loop invariant x >= 0;
  loop invariant y >= 0;
  loop invariant 0 <= y;
  loop invariant 0 <= x;
  loop assigns y;
  loop assigns x;
  */
  while (unknown()) {
    x  = x + 10;
    y  = y + 10;
  }
  if (y == 0) {
    // @ assert x != 20;
  }
}