/*@
  requires 0 <= x <= 10;
  requires 0 <= y <= 10;
*/
void foo(int x, int y) {
  // loop body
  /*@
  loop invariant y - x == \at(y,Pre) - \at(x,Pre);
  loop invariant \at(y,Pre) <= y;
  loop invariant \at(y,Pre) <= 10;
  loop invariant \at(x,Pre) <= x;
  loop invariant \at(x,Pre) <= 10;
  loop invariant 0 <= \at(y,Pre);
  loop invariant 0 <= \at(x,Pre);
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
