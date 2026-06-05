int unknown();

/*@
requires n > 0;
*/
void foo(int n) {
  int c = 0;
  
  /*@
  loop invariant 0 <= c;
  loop invariant c <= n + 1;
  loop invariant (c != n) || c == n;
  loop invariant c <= n+2;
  loop invariant c <= n+1;
  loop invariant c < n+2;
  loop invariant c < n+2;
  loop invariant c < n+2;
  loop invariant c < n+2;
  loop invariant c < n+2;
  loop invariant c < n+2;
  loop invariant c != 0 || n == 0;
  loop invariant c != 0 || (c >= 0);
  loop invariant 0 <= c;
  loop invariant (c > n) ==> (n > 0);
  loop invariant (c == n) ==> (n > -1);
  loop invariant (c == n) ==> (c == n);
  loop assign c;
  */
  while (unknown()) {
    if (unknown()) {
      if (c > n) {
        c  = c + 1;
      }
    } else {
      if (c == n) {
        c  = 1;
      }
    }
  }
  // post-condition
  if (c == n) {
    // @ assert(n > -1);
  }
}