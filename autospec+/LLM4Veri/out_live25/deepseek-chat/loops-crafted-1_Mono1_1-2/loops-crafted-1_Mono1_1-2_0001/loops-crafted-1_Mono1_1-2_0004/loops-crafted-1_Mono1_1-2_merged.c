int main(void) {
  unsigned int x = 0;
  /*@
  loop invariant (x >= 10000000) ==> (x % 2 == 0);
  loop invariant (x < 10000000) ==> (x == \at(x, Pre) + (x - \at(x, Pre)));
  loop invariant x >= 10000000 ==> x % 2 == 0;
  loop invariant x == 10000000 || x == 100000000;
  loop invariant x == 0 || x >= 10000000 ==> x % 2 == 0;
  loop invariant x <= 100000000;
  loop invariant x < 10000000 ==> x == \at(x, Pre) + x;
  loop invariant 0 <= x;
  loop assigns x;
  */
  while (x < 100000000) {
    if (x < 10000000) {
      x++;
    } else {
      x += 2;
    }
  }
  //@ assert(x == 100000000);
}
