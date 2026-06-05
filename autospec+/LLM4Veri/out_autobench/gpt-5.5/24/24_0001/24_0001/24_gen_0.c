/*@
requires i == 1;
requires j == 10;
*/
void foo(int i, int j) {
  // loop body
  /*@
  loop invariant i + 2 * j == 21;
  loop invariant 6 <= j <= 10;
  loop invariant 1 <= i <= 9;
  loop assigns i, j;
  loop variant j - i + 1;
  */
  while (j >= i) {
    i  = i + 2;
    j  = j - 1;
  }
  // post-condition
  // @ assert(j == 6);
}
