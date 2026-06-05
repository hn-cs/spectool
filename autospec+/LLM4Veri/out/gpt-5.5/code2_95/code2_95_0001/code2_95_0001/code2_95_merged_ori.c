void foo(int x) {
  int i = 0;
  int j = 0;
  int y = 0;
  /*@
  loop invariant y == 0;
  loop invariant x - i + 1;
  loop invariant i == j;
  loop invariant i <= x + 1;
  loop invariant 0 <= i;
  loop assigns j;
  loop assigns i;
  */
  while (i <= x) {
    i  = i + 1;
    j  = j + y;
  }
  if (y == 1) {
    // @ assert i == j;
  }
}