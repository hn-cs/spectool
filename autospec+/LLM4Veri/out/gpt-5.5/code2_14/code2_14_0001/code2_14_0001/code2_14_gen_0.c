/*@
  requires 0 <= x <= 2;
  requires 0 <= y <= 2;
*/
void foo(int x, int y) {
  int z1;
  int z2;
  int z3;
  /*@
  loop invariant x - y == \at(x,Pre) - \at(y,Pre);
  loop invariant 0 <= y;
  loop invariant y % 2 == \at(y,Pre) % 2;
  loop invariant x % 2 == \at(x,Pre) % 2;
  loop assigns x, y;
  */
  while (unknown()) {
    x  = x + 2;
    y  = y + 2;
  }
  if (y == 0) {
    // @ assert x != 4;
  }
}