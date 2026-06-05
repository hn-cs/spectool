int main(void) {
  unsigned int x = 0;
  /*@
  loop invariant 0 <= x;
  loop assigns x;
  */
  while (x < 0x0fffffff) {
    if (x < 0xfff0) {
      x++;
    } else {
      x += 2;
    }
  }
}
