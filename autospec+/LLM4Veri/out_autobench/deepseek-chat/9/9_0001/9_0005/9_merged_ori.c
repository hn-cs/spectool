/*@
  requires 0 <= x <= 2;
  requires 0 <= y <= 2;
*/
void foo(int x, int y) {
  // loop body
  /*@
  loop invariant x == y;
  loop invariant x <= 2 * y;
  loop invariant x - y == \at(x - y, Pre);
  loop invariant 0 <= x - y;
  loop invariant 0 <= y;
  loop invariant 0 <= x;
  loop invariant (x == y) -> (x == 2*(x_old) - 1);
  loop invariant (x - y) == 0;
  loop invariant (x - y) <= 2;
  loop invariant (x - y) < 2;
  loop invariant (x - y) % 2 == 0;
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
