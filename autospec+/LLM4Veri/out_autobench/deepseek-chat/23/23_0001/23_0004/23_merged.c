/*@
requires i == 1;
requires j == 20;
*/
void foo(int i, int j) {
  // loop body
  /*@
  loop invariant j <= 20;
  loop invariant j <= 20 || i <= j;
  loop invariant j <= 20 || i <= 20;
  loop invariant i <= 20;
  loop invariant i <= 20 || i <= j;
  loop invariant i < 20;
  loop invariant j == 20 - (i - 1)/2;
  loop invariant j - i;
  loop invariant i % 2 == 1;
  loop invariant 20 - j == (i - 1) / 2;
  loop invariant 2 * (20 - j) == i - 1;
  loop invariant 1 <= i;
  loop invariant 1 < i || i <= j + 1;
  loop invariant (i - 1) % 2 == 0;
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
