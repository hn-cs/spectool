void main() {
  // variable declarations
  int x;
  int y;
  // pre-conditions
  x = 1;
  y = 0;
  // loop body
  /*@
  loop invariant y == 0 || x == (y*(y+1))/2 + 1;
  loop invariant y <= x;
  loop invariant y < x;
  loop invariant y < x;
  loop invariant y < x;
  loop invariant y < x;
  loop invariant y < x;
  loop invariant y < x;
  loop invariant y < x;
  loop invariant x == (y*(y-1))/2 + 1;
  loop invariant 0 <= x;
  loop invariant 0 <= x || y <= x;
  loop invariant 0 < x;
  loop invariant y == 0 ==> x == 1;
  loop invariant y <= 1000;
  loop invariant 1 <= x;
  loop invariant 0 <= y;
  loop assigns y;
  loop assigns x;
  */
  while (y < 1000) {
    x  = (x + y);
    y  = (y + 1);
  }
  // post-condition
  // @ assert(x >= y);
}
