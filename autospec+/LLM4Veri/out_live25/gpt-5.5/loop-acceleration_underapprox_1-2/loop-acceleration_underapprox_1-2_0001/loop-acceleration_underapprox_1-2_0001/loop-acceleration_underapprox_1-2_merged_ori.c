int main(void) {
  unsigned int x = 0;
  unsigned int y = 1;
  /*@
  loop invariant y == (1U << x);
  loop invariant y % 3 != 0;
  loop invariant x <= 6;
  loop invariant 6 - x;
  loop invariant 0 <= x;
  loop assigns y;
  loop assigns x;
  */
  while (x < 6) {
    x++;
    y *= 2;
  }
  // @ assert(y % 3);
}
