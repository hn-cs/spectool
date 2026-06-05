void foo(int x) {
  int lock = 0;
  int y = x + 1;
  /*@
  loop invariant x != y ==> lock == 0 || lock == 1;
  loop invariant x == y ==> lock == 1;
  loop invariant y >= x + 1;
  loop invariant \at(x, Pre) + 1 <= x;
  loop assigns lock, x, y;
  */
  while (x != y) {
    if (unknown()) {
      lock = 1;
      x = y;
    } else {
      lock = 0;
      x = y;
      y = y + 1;
    }
  }
  // @ assert lock == 1;
}