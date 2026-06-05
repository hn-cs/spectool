/*@
  requires 0 <= x <= 10;
  requires 0 <= y <= 10;
*/
void foo(int x, int y) {
  /*@
  loop invariant y % 10 == y;
  loop invariant x >= 10 || y >= 10;
  loop invariant x >= 0 && y >= 0;
  loop invariant x == y + 10 || y == x + 10;
  loop invariant x <= 10 && y <= 10 == > x == x && y == y;
  loop invariant x + y == 10 || x == y;
  loop invariant x % 10 == x;
  loop invariant 0 <= y;
  loop invariant 0 <= x;
  */
  while (unknown()) {
    x  = x + 10;
    y  = y + 10;
  }
  if (y == 0) {
    //@ assert x != 20;
  }
}