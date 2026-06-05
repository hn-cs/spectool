/*@
  requires 0 <= x <= 10;
  requires 0 <= y <= 10;
*/
void foo(int x, int y) {
  // loop body
  /*@
  loop invariant x % 10 == 0;
  loop invariant y % 10 == 0;
  loop invariant x == y + (x - y);
  loop invariant 0 <= x && x <= 20;
  loop invariant 0 <= y && y <= 20;
  loop invariant x - y == \at(x, Pre) - \at(y, Pre);
  loop invariant x >= \at(x, Pre);
  loop invariant y >= \at(y, Pre);
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
