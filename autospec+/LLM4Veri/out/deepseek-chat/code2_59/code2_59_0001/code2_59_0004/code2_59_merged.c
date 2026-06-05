/*@
requires n > 0;
*/
void foo(int n) {
  int c = 0;
  /*@
  loop invariant c == n || c < n;
  loop invariant \forall integer k; 0 <= k <= c ==> (c == n) || (c < n);
  loop invariant (c == 1) ==> (\at(c, Pre) != n);
  loop invariant c >= 0 && c <= n || c == 1;
  loop invariant c == 1 || c <= n;
  loop invariant c <= n + 1;
  loop invariant c % 2 == n % 2 || c == 1;
  loop invariant c != 0;
  loop invariant 0 <= c;
  loop invariant (c == n) ==> (\at(c, Pre) == n);
  loop invariant (c != n) ==> c < n;
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
    //@ assert c <= n;
  }
}