/*@
requires (x == 100);
*/
void foo(int x) { 
  /*@
  loop invariant x >= 0;
  loop invariant x <= 100;
  loop assigns x;
  */
  while (x > 0) {
    x  = x - 1;
  }
  // @ assert x == 0;
}