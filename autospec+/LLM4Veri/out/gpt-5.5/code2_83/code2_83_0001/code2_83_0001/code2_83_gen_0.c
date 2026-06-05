int main() {
  int x = -5000;
  int y = 0;
  /*@
  loop invariant y >= 0;
  loop invariant x == -5000 + (y * (y - 1)) / 2;
  loop assigns x, y;
  */
  while ((x < 0)) {
    x  = x + y;
    y  = y + 1;
  }
  // @ assert y > 0;
}