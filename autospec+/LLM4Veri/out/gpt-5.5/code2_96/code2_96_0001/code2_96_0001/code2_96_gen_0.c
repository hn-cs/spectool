void foo(int x) {
  int i = 0;
  int j = 0;
  int y = 0;
  /*@
  loop invariant i == j;
  loop invariant y == 0;
  loop assigns i, j;
  */
  while (i <= x) {
    i  = i + 1;
    j  = j + y;
  }
  if (i != j) {
    // @ assert y != 1;
  }
}