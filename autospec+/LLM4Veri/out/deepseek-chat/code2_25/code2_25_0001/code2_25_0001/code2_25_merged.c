/*@
requires (x == 10000);
*/
void foo(int x) {
  /*@
  loop invariant x <= \at(x, Pre);
  loop invariant 0 <= x;
  loop assigns x;
  */
  while ((x > 0)) {
    (x  = (x - 1));
  }
  //@ assert  (x == 0) ;
}