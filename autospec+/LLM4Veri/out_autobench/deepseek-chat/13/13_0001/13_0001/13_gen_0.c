/*@
  requires 0 <= x <= 2;
  requires 0 <= y <= 2;
*/
void foo(int x, int y) {
  // loop body
  /*@
  loop invariant 0 <= x <= 6;
  loop invariant 0 <= y <= 6;
  loop invariant (x >= 0 && y >= 0);
  loop invariant (x - y) % 2 == 0;
  loop assigns x, y;
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
