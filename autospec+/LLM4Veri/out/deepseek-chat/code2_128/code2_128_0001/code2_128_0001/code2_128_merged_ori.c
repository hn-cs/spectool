void foo(int y) {
  int x = 1;
  /*@
  loop invariant y - x;
  loop invariant x == 1 || x >= 2;
  loop invariant x <= y;
  loop invariant \exists integer k; x == (int)1 << k;
  loop invariant 1 <= x;
  loop assigns x;
  */
  while (x < y) {
    x = x + x;
  }
  // @ assert x >= 1;
}