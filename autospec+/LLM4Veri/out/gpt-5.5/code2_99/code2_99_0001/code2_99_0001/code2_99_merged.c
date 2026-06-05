/*@
requires n >= 0;
*/
void foo(int n) {
  int x = n;
  int y = 0;
  /*@
  loop invariant n == x + y;
  loop invariant 0 <= y;
  loop invariant 0 <= x;
  loop assigns y;
  loop assigns x;
  */
  while (x > 0) {
    y  = y + 1;
    x  = x - 1;
  }
  //@ assert n == x + y;
}