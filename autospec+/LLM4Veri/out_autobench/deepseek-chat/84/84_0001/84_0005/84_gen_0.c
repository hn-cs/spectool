int main() {
  int x = -50;
  int y = 0;

  /*@
  loop invariant x <= 0;
  loop invariant x == -50 + \at(y, Pre);
  loop invariant y >= 0;
  loop invariant x >= -50;
  loop invariant y == y;
  loop invariant 0 <= y;
  loop invariant -50 <= x;
  loop assigns y;
  loop assigns x;
  */
  while (x < 0) {
    x  = x + y;
    y  = y + 1;
  }
  // post-condition
  // @ assert(y > 0);
}
