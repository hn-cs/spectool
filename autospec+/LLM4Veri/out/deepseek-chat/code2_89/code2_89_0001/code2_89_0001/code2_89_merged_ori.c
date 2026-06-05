/*@
requires x == y;
*/
void foo(int x, int y) {
  int lock = 1;
  /*@
  loop invariant x == y || x == y + 1;
  loop invariant lock == 0 || lock == 1;
  loop invariant \old(x) == \old(y);
  loop assigns y;
  loop assigns x;
  loop assigns lock;
  */
  while (x != y) {  
    if (unknown()) {
      lock = 1;
      x = y;
    } else {
      lock  = 0;
      x  = y;
      y  = y + 1; 
    }
  }
  // @ assert lock == 1;
}