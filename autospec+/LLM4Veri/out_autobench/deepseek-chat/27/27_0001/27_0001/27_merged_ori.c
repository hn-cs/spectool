/*@
requires x == n;
requires n >= 1;
*/
void foo(int x, int n) {
  // loop body
  /*@
  loop invariant x;
  loop invariant 1 <= x;
  loop assigns x;
  */
  while (x > 1) {
    x  = x - 1;
  }
  // post-condition
  if (n >= 0) {
    // @ assert(x == 1);
  }
}