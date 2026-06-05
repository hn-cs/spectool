void foo(int x, int y) {
  int i = x;
  int j = y;
  /*@
  loop invariant x == i - (i - x);
  loop invariant i - x == j - y;
  loop invariant 0 <= x;
  loop assigns y;
  loop assigns x;
  */
  while (x != 0) {
    x  = x - 1;
    y  = y - 1;
  }
  if (y != 0) {
    // @ assert i != j;
  }
}