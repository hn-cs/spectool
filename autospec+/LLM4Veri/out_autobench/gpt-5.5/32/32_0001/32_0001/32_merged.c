/*@
requires n >= 1;
*/
void foo(int n) {
  int x = n;
  // loop body
  /*@
  loop invariant x <= n;
  loop invariant 1 <= x;
  loop assigns x;
  */
  while (x > 1) {
    x  = x - 1;
  }
  // post-condition
  if (n >= 0) {
    //@ assert(x == 1);
  }
}
