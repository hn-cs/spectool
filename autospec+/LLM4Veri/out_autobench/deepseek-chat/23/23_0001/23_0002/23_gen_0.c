/*@
requires i == 1;
requires j == 20;
*/
void foo(int i, int j) {
  // loop body
  /*@
  loop invariant j - i == 20 - 2*i;
  loop invariant j + 2*i == 22;
  loop invariant j == 20 - (i - 1)/2;
  loop invariant i <= 2*j - 13;
  loop invariant i >= j + 2;
  loop invariant j >= i;
  loop invariant j - i;
  loop invariant 20 - j == (i - 1) / 2;
  loop invariant (i - 1) % 2 == 0;
  loop assigns j;
  loop assigns i;
  */
  while (j >= i) {
    i  = i + 2;
    j  = j - 1;
  }
  // post-condition
  // @ assert(j == 13);
}
