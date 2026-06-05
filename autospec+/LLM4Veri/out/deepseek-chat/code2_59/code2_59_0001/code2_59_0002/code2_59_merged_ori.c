/*@
requires n > 0;
*/
void foo(int n) {
  int c = 0;
  /*@
  loop invariant c >= 0 && c <= n || c == 1;
  loop invariant c <= n + 1;
  loop invariant (c == n) ==> (\at(c, Pre) == n);
  loop invariant (c != n) ==> c < n;
  loop invariant 0 <= c;
  */
  while (unknown()) {
    if (unknown()) {
      if (c != n) {
        c = c + 1;
      }
    } else {
      if (c == n) {
        c = 1;
      }
    }
  }
  if (c != n) {
    // @ assert c <= n;
  }
}