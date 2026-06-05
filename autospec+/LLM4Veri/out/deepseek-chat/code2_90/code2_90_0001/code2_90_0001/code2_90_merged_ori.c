void foo(int x) {
  int lock = 0;
  int y = x + 1;
  /*@
  loop invariant x <= y;
  loop invariant x != y ==> lock == 1;
  loop invariant 1 <= x;
  loop invariant (y - x);
  loop assigns y;
  loop assigns x;
  loop assigns lock;
  */
  while (x != y) {
    if (unknown()) {
      lock = 1;
      x  = y;
    } else {
      lock = 0;
      x  = y;
      y  = y + 1;
    }
  }
  // @ assert lock == 1;
}