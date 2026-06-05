/*@
  requires 0 <= x <= 10;
  requires 0 <= y <= 10;
*/
void foo(int x, int y) {
  // loop body
  /*@
  loop invariant 0 <= \at(x,Pre) <= 10;
  loop invariant 0 <= \at(y,Pre) <= 10;
  loop invariant y - x == \at(y,Pre) - \at(x,Pre);
  loop invariant x >= \at(x,Pre);
  loop invariant y >= \at(y,Pre);
  loop assigns x, y;
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
