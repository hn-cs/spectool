void main() {
  int x;
  int y;
  x = 1;
  y = 0;
  /*@
  loop invariant x == 1 + (y * (y - 1)) / 2;
  loop invariant x >= 1;
  loop invariant x >= y;
  loop invariant y == 0 ==> x == 1;
  loop invariant y >= 2 ==> x >= 2;
  loop invariant y <= 100000;
  loop invariant 0 <= y;
  loop assigns y;
  loop assigns x;
  */
  while (y < 100000) {
    x  = x + y;
    y  = y + 1;
  }
  // @ assert  (x >= y) ;
}