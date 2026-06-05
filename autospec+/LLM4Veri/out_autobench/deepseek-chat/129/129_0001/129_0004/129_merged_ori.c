void foo(int y) {
  int x = 1;
  
  /*@
  loop invariant x == (1 << i);
  loop invariant x <= 2*y;
  loop invariant x < 2*y;
  loop invariant y - x;
  loop invariant x == 2^(i);
  loop invariant x <= y;
  loop invariant \exists integer k; 0 <= k && x == 2^k;
  loop invariant \exists integer k; 0 <= k && x <= 2 * 2^k;
  loop invariant 1 <= x;
  loop invariant 0 <= y - x;
  loop invariant 0 < y - x;
  loop assigns x;
  */
  while (x < y) {
    x = x + x;
  }
  // post-condition
  // @ assert(x >= 1);
}
