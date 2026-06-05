/*@
  requires 0 <= x <= 2;
  requires 0 <= y <= 2;
*/
void foo(int x, int y) {
  // loop body
  /*@
  loop invariant y <= 4;
  loop invariant y < 4;
  loop invariant y % 2 == 0;
  loop invariant x <= 4;
  loop invariant x <= 4 || y <= 4;
  loop invariant x < 4;
  loop invariant x % 2 == 0;
  loop invariant (x - y) == 0;
  loop invariant 0 <= y;
  loop invariant 0 <= x;
  loop invariant (x >= 0 && y >= 0);
  loop invariant (x - y) == (x - y);
  loop assigns y;
  loop assigns x;
  */
  while (unknown()) {
    x  = x + 2;
    y  = y + 2;
  }
  // post-condition
  if (x == 4) {
    // @ assert(y != 0);
  }
}
