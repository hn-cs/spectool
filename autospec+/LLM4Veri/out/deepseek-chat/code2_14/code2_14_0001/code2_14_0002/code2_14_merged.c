/*@
  requires 0 <= x <= 2;
  requires 0 <= y <= 2;
*/
void foo(int x, int y) {
  int z1;
  int z2;
  int z3;
  /*@
  loop invariant y % 2 == 0;
  loop invariant x == 0 || x == 2 || x == 4;
  loop invariant x + y == \old(x) + \old(y) + 4 * (x/2 - \old(x)/2);
  loop invariant x % 2 == 0;
  loop assigns y;
  loop assigns x;
  */
  while (unknown()) {
    x  = x + 2;
    y  = y + 2;
  }
  if (y == 0) {
    //@ assert x != 4;
  }
}