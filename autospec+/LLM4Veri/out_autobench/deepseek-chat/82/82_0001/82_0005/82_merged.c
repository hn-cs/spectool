/*@
requires x >= 0;
requires y >= 0;
requires x >= y;
*/
void foo(int x, int y) {
  int i = 0;
  
  /*@
  loop invariant y <= x;
  loop invariant i == \at(i, Pre) || i == \at(i, Pre) + 1;
  loop invariant i <= y;
  loop invariant i <= x;
  loop invariant \at(i, Pre) <= i;
  loop invariant 0 <= i;
  loop assigns i;
  */
  while (unknown()) {
    if (i < y)
    {
      i = i + 1;
    }
  }
  // post-condition
  if (i >= x) {
    if (0 > i) {
      //@ assert(i >= y);
    }
  }
}
