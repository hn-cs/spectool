/*@
  requires 0 <= x <= 10;
  requires 0 <= y <= 10;
*/
void foo(int x, int y) {
  /*@
  loop invariant y % 10 == y;
  loop invariant y % 10 == y - (y / 10) * 10;
  loop invariant x >= 0 && y >= 0;
  loop invariant x % 10 == x;
  loop invariant x % 10 == x - (x / 10) * 10;
  loop invariant 0 <= x && 0 <= y;
  loop assigns y;
  loop assigns x;
  */
  while (unknown()) {
    x  = x + 10;
    y  = y + 10;
  }
  if (x == 20) {
    // @ assert y != 0;
  }
}