int main(void) {
  unsigned int x = 0;
  unsigned int y = 1;
  /*@
  loop invariant x <= 6;
  loop invariant y == (1 << x);
  loop invariant x <= 6;
  loop assigns x;
  loop assigns y;
  */
  while (x < 6) {
    x++;
    y *= 2;
  }
  // @ assert(y % 3);
}
