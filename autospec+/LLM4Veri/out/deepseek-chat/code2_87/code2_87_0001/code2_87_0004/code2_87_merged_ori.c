void foo(int x, int y) {
  int lock = 1;
  /*@
  loop invariant x <= y;
  loop invariant x < y;
  loop invariant lock == 1 ==> x == y;
  loop invariant lock == 0 ==> x < y;
  loop invariant \old(x) <= x;
  loop invariant \old(x) <= x || x <= y;
  loop invariant \old(x) < x;
  loop invariant y - x == 0 ==> lock == 1;
  loop invariant x == y ==> lock == 1;
  loop invariant x != y ==> lock <= 1;
  loop invariant x != y ==> (lock == 0 || lock == 1);
  loop invariant lock == 0 || lock == 1;
  loop invariant lock <= 2;
  loop invariant \old(y) <= y;
  loop invariant 1 <= lock;
  loop invariant (1 <= lock) && (lock <= 2);
  loop assigns y;
  loop assigns x;
  loop assigns lock;
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