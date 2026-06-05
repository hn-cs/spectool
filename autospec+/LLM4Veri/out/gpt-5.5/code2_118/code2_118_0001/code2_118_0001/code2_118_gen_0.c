/*@
requires size >= 1;
*/
void foo(int size) {
  int i = 1;
  int sn = 0;
  /*@
  loop invariant 1 <= i <= size + 1;
  loop invariant sn == i - 1;
  loop invariant 0 <= sn <= size;
  loop assigns i, sn;
  loop variant size - i + 1;
  */
  while (i <= size) {
    i = i + 1;
    sn = sn + 1;
  }
  if(sn != size) {
    // @ assert sn == 0;
  }
}