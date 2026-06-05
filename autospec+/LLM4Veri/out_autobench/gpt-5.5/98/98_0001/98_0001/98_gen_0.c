void foo(int x) {
  int i = 0;
  int j = 0;
  int y = 2;

  /*@
  loop invariant i >= 0;
  loop invariant y == 2;
  loop invariant j == y * i;
  loop invariant x >= 0 ==> i <= x + 1;
  loop assigns i, j;
  */
  while (i <= x) {
    i  = i + 1;
    j  = j + y;
  }
  // post-condition
  if (i != j) {
    // @ assert(y != 1);
  }
}
