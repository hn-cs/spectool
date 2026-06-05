void main() {
  int x;
  int y;
  x = 1;
  y = 0;
  /*@
  loop invariant y <= 100000;
  loop invariant 0 <= y;
  loop assigns y;
  loop assigns x;
  */
  while (y < 100000) {
    x  = x + y;
    y  = y + 1;
  }
  //@ assert  (x >= y) ;
}