void foo(int n) {
  int x = 0;
  
  /*@
  loop invariant 0 <= x <= n;
  loop assigns x;
  */
  while (x < n) {
    x = x + 1;
  }
  // post-condition
  if (x != n) {
    // @ assert(n < 0);
  }
}
