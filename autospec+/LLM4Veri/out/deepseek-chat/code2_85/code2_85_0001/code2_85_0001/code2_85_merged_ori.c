int main() {
  int x = -15000;
  int y = 0;
  /*@
  loop invariant x <= 0;
  loop invariant 0 <= y;
  loop invariant -x;
  loop invariant -15000 <= x;
  loop invariant -15000 + (y*(y-1))/2 <= x;
  loop assigns y;
  loop assigns x;
  */
  while (x < 0) {
    x  = x + y;
    y  = y + 1;
  }
  // @ assert y > 0;
}