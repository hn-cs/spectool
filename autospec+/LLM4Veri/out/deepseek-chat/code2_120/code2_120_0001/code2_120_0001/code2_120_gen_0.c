int main() {
  int i = 1;
  int sn = 0;
  /*@
  loop invariant 1 <= i <= 9;
  loop invariant i == sn + 1;
  loop invariant sn <= 8;
  loop assigns i, sn;
  */
  while (i <= 8) {
    i = i + 1;
    sn = sn + 1;
  }
  if (sn != 8) {
    // @ assert sn == 0;
  }
}