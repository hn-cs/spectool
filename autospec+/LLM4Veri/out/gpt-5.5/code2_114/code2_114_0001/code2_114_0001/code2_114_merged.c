int main() {
  int sn = 0;
  int x = 0;
  /*@
  loop invariant sn == x;
  loop assigns x;
  loop assigns sn;
  */
  while (unknown()) {
    x = x + 1;
    sn = sn + 1;
  }
  if(sn != x) {
    //@ assert sn == -1;
  }
}