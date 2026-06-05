void foo(int y) {
  int x = 1;
  
  /*@
  loop invariant 1 <= x <= y;
  loop invariant \exists integer k; 0 <= k ==> x == 1 << k;
  loop assigns x;
  loop variant y - x;
  */
  while (x < y) {
    x = x + x;
  }
  // post-condition
  // @ assert(x >= 1);
}
