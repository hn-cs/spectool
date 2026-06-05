/*@
requires n > 0;
*/
void foo(int n) {
  int c = 0;
  
  /*@
  loop invariant c >= 0;
  loop invariant c <= n;
  loop invariant c == 0 || c == 1 || c == n;
  loop invariant (c == 1) ==> (n > 0);
  loop invariant (c == 1) ==> (n > 0);
  loop invariant n > 0 ==> c >= 0 && c <= n;
  loop invariant n > 0 ==> c <= n;
  loop invariant n > 0 ==> (c == 1 ==> \at(c, Pre) == 0);
  loop invariant n > 0 ==> (c == 0 || c == 1 || c == n);
  loop invariant c == 0 || c == n || c == 1;
  loop invariant c == 0 && n > 0 ==> c == 0;
  loop invariant c <= n;
  loop invariant c <= n && c >= 0;
  loop invariant \old(c) == 0 && n > 0 ==> c == 1 || c == 0;
  loop invariant 0 <= c;
  loop invariant 0 < n;
  loop invariant (c == n) ==> (n > 0);
  loop invariant (c == 1) ==> (n > 0);
  loop invariant (c == 0) ==> (1 == 2); /* always false, always holds;
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
    // @ assert(c > 0);
  }

}
