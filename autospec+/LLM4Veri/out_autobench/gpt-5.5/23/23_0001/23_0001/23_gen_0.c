/*@
requires i == 1;
requires j == 20;
*/
void foo(int i, int j) {
  // loop body
  /*@
  loop invariant i == 1 + 2 * (20 - j);
  loop invariant 1 <= i <= 15;
  loop invariant 13 <= j <= 20;
  loop invariant j >= i || j == 13;
  loop assigns i, j;
  loop variant j - i + 1;
  */
  while (j >= i) {
    i  = i + 2;
    j  = j - 1;
  }
  // post-condition
  // @ assert(j == 13);
}
