/*@
requires n >= 0;
*/
void foo(int n) {
  int x = 0;
  /*@
  loop invariant 0 <= x <= n;
  loop invariant x == \at(x, Pre) + (\at(x, Here) - \at(x, Pre));
  loop assigns x;
  */
  while (x < n) {
    x  = x + 1;
  }
  if(n >= 0) {
    // @ assert x == n;
  }
}