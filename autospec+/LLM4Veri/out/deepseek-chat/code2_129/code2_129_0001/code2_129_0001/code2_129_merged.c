void foo(int y) {
  int x = 1;
  /*@
  loop invariant x == 1 || x % 2 == 0;
  loop invariant 1 <= x;
  loop assigns x;
  */
  while (x < y) {
    x = x + x;
  }
  //@ assert x >= 1;
}