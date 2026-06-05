void foo(int x) {
  int i = 0;
  int j = 0;
  int y = 0;
  /*@
  loop invariant 0 <= i <= x+1;
  loop invariant j == 0;
  loop assigns i, j;
  */
  while (i <= x) {
    i  = i + 1;
    j  = j + y;
  }
  if (y == 1) {
    // @ assert i == j;
  }
}