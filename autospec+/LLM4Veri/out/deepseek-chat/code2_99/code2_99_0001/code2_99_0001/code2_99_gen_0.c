/*@
requires n >= 0;
*/
void foo(int n) {
  int x = n;
  int y = 0;
  /*@
  loop invariant 0 <= x <= n;
  loop invariant y == n - x;
  loop invariant x + y == n;
  loop assigns x, y;
  */
  while (x > 0) {
    y  = y + 1;
    x  = x - 1;
  }
  // @ assert n == x + y;
}