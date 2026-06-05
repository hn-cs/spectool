/*@
requires n > 0;
*/
void foo(int n) {
  int c = 0;
  
  /*@
  loop invariant n - c <= n;
  loop invariant c == n || c + 1 <= n;
  loop invariant c == 0 ==> n - c == n;
  loop invariant c < n ==> c + 1 <= n;
  loop invariant c != 0 ==> 1 <= c;
  loop invariant 0 <= n - c;
  loop invariant 0 <= n - c || n - c <= n;
  loop invariant c == n || c < n;
  loop invariant c == 0 || 1 <= c;
  loop invariant c <= n;
  loop invariant c + 1 <= n + 1;
  loop invariant c != n ==> c < n;
  loop invariant 1 <= n;
  loop invariant 0 <= c;
  loop invariant 0 < n;
  loop assigns c;
  */
  while (unknown()) {
    if (unknown()) {
      if (c != n)
      {
        c = c + 1;
      }
    } else {
      if (c == n)
      {
        c = 1;
      }
    }
  }
  // post-condition
  if (n > -1){
    //@ assert(c > 0);
  }

}
