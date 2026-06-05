/*@
  requires 0 <= x <= 10;
  requires 0 <= y <= 10;
*/
void foo(int x, int y) {
  /*@
  loop invariant x - y == \at(x,Pre) - \at(y,Pre);
  loop invariant \at(y,Pre) <= y;
  loop assigns y;
  loop assigns x;
  */
  while (unknown()) {
    x  = x + 10;
    y  = y + 10;
  }
  if (y == 0) {
    //@ assert x != 20;
  }
}