/*@
requires i == 1;
requires j == 20;
*/
void foo(int i, int j) {
  // loop body
  /*@
  loop invariant j >= i || j == 13;
  loop invariant j <= 20;
  loop invariant j - i + 1;
  loop invariant i == 1 + 2 * (20 - j);
  loop invariant i <= 15;
  loop invariant 13 <= j;
  loop invariant 1 <= i;
  loop assigns j;
  loop assigns i;
  */
  while (j >= i) {
    i  = i + 2;
    j  = j - 1;
  }
  // post-condition
  //@ assert(j == 13);
}
