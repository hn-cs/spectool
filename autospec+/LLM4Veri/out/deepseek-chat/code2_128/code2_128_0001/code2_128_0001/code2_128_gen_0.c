void foo(int y) {
  int x = 1;
  /*@
  loop invariant 1 <= x <= y;
  loop invariant x == 1 || x >= 2;
  loop invariant \exists integer k; x == (int)1 << k;
  loop assigns x;
  loop variant y - x;
  */
  while (x < y) {
    x = x + x;
  }
  // @ assert x >= 1;
}