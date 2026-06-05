/*@
requires i == 1;
requires j == 10;
*/
void foo(int i, int j) {
  // loop body
  /*@
  loop invariant 1 <= i <= 11;
  loop invariant i + 2*j == 21;
  loop invariant i == 1 + 2*(10 - j);
  loop assigns i, j;
  */
  while (j >= i) {
    i  = i + 2;
    j  = j - 1;
  }
  // post-condition
  // @ assert(j == 6);
}
