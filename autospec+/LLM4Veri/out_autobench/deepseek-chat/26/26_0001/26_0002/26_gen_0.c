/*@
requires x == n;
requires x != 1;
*/
void foo(int x, int n) {
  // loop body
  /*@
  loop invariant 0 <= x <= n;
  loop invariant x >= 1;
  loop invariant n >= 1;
  loop invariant x == n - (initial_n - x);
  loop invariant \exists integer k; 0 <= k && x + k == n;
  loop invariant x <= n;
  loop assigns x;
  */
  while (x > 1) {
    x  = x - 1;
  }
  // post-condition
  if (x != 1) {
    // @ assert(n < 1);
  }
}
