/*@
  requires 0 <= x <= 2;
  requires 0 <= y <= 2;
*/
void foo(int x, int y) {
  /*@
  loop invariant x == y || (x != 4);
  loop invariant x - y == \at(x,Pre) - \at(y,Pre);
  loop invariant 0 <= y;
  loop assigns y;
  loop assigns x;
  */
  while (unknown()) {
    x  = x + 2;
    y  = y + 2;
  }
  if (x == 4) {
    // @ assert y != 0;
  }
}