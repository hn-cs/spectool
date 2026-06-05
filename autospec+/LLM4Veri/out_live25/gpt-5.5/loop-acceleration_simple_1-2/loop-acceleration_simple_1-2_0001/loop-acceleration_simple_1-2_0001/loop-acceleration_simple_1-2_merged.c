int main(void) {
  unsigned int x = 0;
  /*@
  loop invariant x <= 0x10000000;
  loop invariant x % 2 == 0;
  loop assigns x;
  */
  while (x < 0x0fffffff) {
    x += 2;
  }
  //@ assert(!(x % 2));
}
