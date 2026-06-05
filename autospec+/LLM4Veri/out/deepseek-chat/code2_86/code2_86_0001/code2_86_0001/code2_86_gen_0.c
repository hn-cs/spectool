int main() {
  int x = -50;
  int y = 0;
  /*@
  loop invariant x >= -50;
  loop invariant y >= 0;
  loop invariant x + y * (y + 1) / 2 == -50;
  loop assigns x, y;
  */
  while (x < 0) {
    x  = x + y;
    y  = y + 1;
  }
  // @ assert y > 0;
}