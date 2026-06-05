/*@
  requires 0 <= x <= 2;
  requires 0 <= y <= 2;
*/
void foo(int x, int y) {
  // loop body
  /*@
  loop invariant x % 2 == x - 2*(x/2);
  loop invariant y % 2 == y - 2*(y/2);
  loop invariant 0 <= x;
  loop invariant 0 <= y;
  loop invariant x == y;
  loop invariant x >= 0;
  loop invariant y >= 0;
  loop invariant y % 2 == y - 2*(y/2);
  loop invariant x % 2 == x - 2*(x/2);
  loop invariant 0 <= y;
  loop invariant 0 <= x;
  loop assigns y;
  loop assigns x;
  */
  while (unknown()) {
    x  = x + 2;
    y  = y + 2;
  }
  // post-condition
  if (y == 0) {
    // @ assert(x != 4);
  }
}
