/*@
requires i == 1;
requires j == 20;
*/
void foo(int i, int j) {
  // loop body
  /*@
  loop invariant i <= j;
  loop invariant (i - 1) % 2 == 0;
  loop invariant 20 - j == (i - 1) / 2;
  loop assigns i, j;
  loop variant j - i;
  */
  while (j >= i) {
    i  = i + 2;
    j  = j - 1;
  }
  // post-condition
  // @ assert(j == 13);
}
