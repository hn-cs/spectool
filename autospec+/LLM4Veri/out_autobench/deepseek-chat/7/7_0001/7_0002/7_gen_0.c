/*@
  requires 0 <= x <= 10;
  requires 0 <= y <= 10;
*/
void foo(int x, int y) {
  // loop body
  /*@
  loop invariant x % 10 == 0;
  loop invariant y % 10 == 0;
  loop invariant x >= 0;
  loop invariant y >= 0;
  loop invariant x == y;
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
