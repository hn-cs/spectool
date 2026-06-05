/*@
  requires 0 <= x <= 10;
  requires 0 <= y <= 10;
*/
void foo(int x, int y) {
  /*@
  loop invariant x >= y;
  loop invariant x % 10 == x;
  loop invariant y % 10 == y;
  loop invariant x == y;
  loop invariant 0 <= x <= 20;
  loop invariant 0 <= y <= 20;
  loop invariant 0 <= y;
  loop invariant 0 <= x;
  */
  while (unknown()) {
    x  = x + 10;
    y  = y + 10;
  }
  if (y == 0) {
    // @ assert x != 20;
  }
}