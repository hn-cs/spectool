int main() {
  int i = 1;
  int sn = 0;
  /*@
  loop invariant sn <= 8;
  loop invariant i == sn + 1;
  loop invariant i <= 9;
  loop invariant 1 <= i;
  loop assigns sn;
  loop assigns i;
  */
  while (i <= 8) {
    i = i + 1;
    sn = sn + 1;
  }
  if (sn != 8) {
    // @ assert sn == 0;
  }
}