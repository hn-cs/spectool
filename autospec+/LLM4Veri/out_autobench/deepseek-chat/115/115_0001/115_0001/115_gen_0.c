int main() {
  int sn = 0;
  int x = 0;
  
  /*@
  loop invariant sn == x;
  loop invariant x >= 0;
  loop invariant sn >= 0;
  loop assigns x, sn;
  */
  while (unknown()) {
    x  = x + 1;
    sn  = sn + 1;
  }
  // post-condition
  if (sn != -1) {
    // @ assert(sn == x);
  }
}
