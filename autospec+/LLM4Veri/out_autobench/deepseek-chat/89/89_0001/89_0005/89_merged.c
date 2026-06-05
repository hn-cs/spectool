/*@
requires x == y;
*/
void foo(int x, int y) {
  int lock = 1;
  
  /*@
  loop invariant x == y || x == y + 1;
  loop invariant x - y <= 1;
  loop invariant 0 <= x - y;
  loop invariant (lock == 1) <==> (x == y);
  loop invariant (lock == 0) <==> (x != y);
  loop invariants (lock == 1) ==> (x == y);
  loop invariant x == y;
  loop invariant lock == 1 <==> x == y;
  loop invariant lock == 0 || lock == 1;
  loop invariant lock == 0 <==> x != y;
  loop invariant \at(x, Pre) == \at(y, Pre);
  loop invariant \at(x, Here) == \at(y, Here) <==> lock != 0;
  loop invariant (x == y) || (x != y && lock != 0);
  loop invariant (lock == 1) ==> (x == y);
  loop invariant (lock == 0) ==> (x == y + 1);
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
  // post-condition
  //@ assert(lock == 1);
}
