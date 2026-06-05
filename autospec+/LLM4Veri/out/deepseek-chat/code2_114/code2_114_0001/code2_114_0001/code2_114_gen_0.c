int main() {
  int sn = 0;
  int x = 0;
  /*@
  loop invariant 0 <= x;
  loop invariant 0 <= sn;
  loop invariant sn == x;
  loop assigns x, sn;
  */
  while (unknown()) {
    x = x + 1;
    sn = sn + 1;
  }
  if(sn != x) {
    // @ assert sn == -1;
  }
}