void foo(int x, int y) {
  int i = x;
  int j = y;
  /*@
  loop invariant 0 <= x <= i;
  loop invariant y - x == j - i;
  loop invariant y == j - (i - x);
  loop assigns x, y;
  */
  while (x != 0) {
    x  = x - 1;
    y  = y - 1;
  }
  if (i == j) {
    // @ assert y == 0;
  }
}