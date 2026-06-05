void foo(int x) {
  int lock = 0;
  int y = x + 1;
  /*@
  loop invariant y == \old(y) + (lock == 0 ? (\count()) : 0);
  loop invariant x == \old(y) || x == y;
  loop invariant lock == 0 <==> y > \at(y, Pre);
  loop invariant lock == 1 ==> x == \at(y, Pre) && y == \at(y, Pre);
  loop invariant x <= y;
  loop invariant x + 1 <= y;
  loop invariant lock == 0 || lock == 1;
  loop invariant \old(y) <= y;
  loop invariant (lock == 1) ==> (y == \at(y, Pre));
  loop invariant (lock == 1) ==> (x == y);
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