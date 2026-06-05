/*@
  requires 0 <= x <= 10;
  requires 0 <= y <= 10;
*/
void foo(int x, int y) {
  // variable declarations
  int z1;
  int z2;
  int z3;

  // loop body
  /*@
  loop invariant y % 10 == \at(y, Pre) || y % 10 == \at(y, Pre) % 10;
  loop invariant x % 10 == \at(x, Pre) || x % 10 == \at(x, Pre) % 10;
  loop invariant \at(x, Pre) <= x;
  loop invariant \at(x, Pre) <= x || x <= \at(x, Pre) + 10;
  loop invariant (x - y) == \at(x - y, Pre);
  loop invariant x == y ==> x == y;
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
  if (y == 0) {
    //@ assert(x != 20);
  }
}
