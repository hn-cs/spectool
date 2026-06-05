/*@
requires n >= 0;
*/
void foo(int n) {
  int x = 0;
  /*@
  loop invariant n - x >= 0;
  loop invariant x == 0 || x >= 0;
  loop invariant \at(x, LoopEntry) == \at(x, Pre) + \at(x, Here);
  loop invariant x > 0 ==> x == n;
  loop invariant x == x % (n+1);
  loop invariant x == n || x == 0;
  loop invariant x == n || (x < n && x >= 0);
  loop invariant x == n ==> \at(x, LoopEntry) < n;
  loop invariant x == n % (x+1);
  loop invariant x == \at(x,Pre) + (1*\at(x,Here));
  loop invariant x == \at(x, Pre) + \at(x, Here);
  loop invariant x == \at(x, Pre) + (\at(x, Here) - \at(x, Pre));
  loop invariant x == (x == n) ? n : x;
  loop invariant x <= n;
  loop invariant x + (n - x) == n;
  loop invariant 0 <= x;
  loop assigns x;
  */
  while (x < n) {
    x  = x + 1;
  }
  if(n >= 0) {
    // @ assert x == n;
  }
}