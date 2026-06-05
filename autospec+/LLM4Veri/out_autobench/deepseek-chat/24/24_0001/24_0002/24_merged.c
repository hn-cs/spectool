/*@
requires i == 1;
requires j == 10;
*/
void foo(int i, int j) {
  // loop body
  /*@
  loop invariant j <= 10;
  loop invariant i % 2 == 1;
  loop invariant 0 <= j;
  loop invariant i == 1 + 2*(10 - j);
  loop invariant i <= 11;
  loop invariant i + 2*j == 21;
  loop invariant 1 <= i;
  loop assigns j;
  loop assigns i;
  */
  while (j >= i) {
    i  = i + 2;
    j  = j - 1;
  }
  // post-condition
  //@ assert(j == 6);
}
