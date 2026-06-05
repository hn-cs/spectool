int main() {
  int x = -50;
  int y = 0;
  /*@
  loop invariant 2 * x == y * (y - 1) - 100;
  loop invariant 0 <= y;
  loop assigns y;
  loop assigns x;
  */
  while (x < 0) {
    x  = x + y;
    y  = y + 1;
  }
  // @ assert y > 0;
}