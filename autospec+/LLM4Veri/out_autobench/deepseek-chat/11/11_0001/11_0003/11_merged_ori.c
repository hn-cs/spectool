/*@
  requires 0 <= x <= 10;
  requires 0 <= y <= 10;
*/
void foo(int x, int y) {
  // loop body
  /*@
  loop invariant y == 10 || y == 20 || y == 30;
  loop invariant y % 10 == y;
  loop invariant x == y;
  loop invariant x == 10 || x == 20 || x == 30;
  loop invariant x <= 10 || (x > 10 && y <= 20);
  loop invariant x % 10 == x;
  loop assigns y;
  loop assigns x;
  */
  while (unknown()) {
    x  = x + 10;
    y  = y + 10;
  }
  // post-condition
  if (x == 20) {
    // @ assert(y != 0);
  }
}
