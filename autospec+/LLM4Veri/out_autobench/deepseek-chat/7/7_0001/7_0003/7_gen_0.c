/*@
  requires 0 <= x <= 10;
  requires 0 <= y <= 10;
*/
void foo(int x, int y) {
  // loop body
  /*@
  loop invariant x - y == \at(x, Pre) - \at(y, Pre);
  loop invariant x >= \at(x, Pre);
  loop invariant y >= \at(y, Pre);
  loop invariant x % 10 == \at(x, Pre) % 10;
  loop invariant y % 10 == \at(y, Pre) % 10;
  loop invariant 0 <= y;
  loop invariant 0 <= x;
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
