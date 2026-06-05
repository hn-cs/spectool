void foo(int x, int y) {
  int lock = 1;
  /*@
  loop invariant 1 <= lock <= 2;
  loop invariant \old(y) <= y;
  loop invariant x != y ==> lock <= 1;
  loop assigns lock, x, y;
  */
  while ((x != y)) {
      if (unknown()) {
        lock  = 1;
        x = y;
      } else {
        lock = 0;
        x = y;
        y = y + 1;
      }
  }
  // @ assert lock == 1;
}