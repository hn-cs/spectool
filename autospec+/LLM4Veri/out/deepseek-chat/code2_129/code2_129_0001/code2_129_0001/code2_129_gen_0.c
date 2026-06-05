void foo(int y) {
  int x = 1;
  /*@
  loop invariant 1 <= x <= y;
  loop invariant x == 1 || x % 2 == 0;
  loop assigns x;
  loop variant y - x;
  */
  while (x < y) {
    x = x + x;
  }
  // @ assert x >= 1;
}