int main() {
  int x = -5000;
  int y = 0;
  
  /*@
  loop invariant x == -5000 + (y * (y - 1)) / 2;
  loop invariant 2 * x == y * (y - 1) - 10000;
  loop invariant y <= 101;
  loop invariant x <= 50;
  loop invariant x < y;
  loop invariant y == 0 ==> x == -5000;
  loop invariant x <= 0 || y > 0;
  loop invariant 0 <= y;
  loop invariant -5000 <= x;
  loop assigns y;
  loop assigns x;
  */
  while ((x < 0)) {
    x  = x + y;
    y  = y + 1;
  }
  // post-condition
  // @ assert(y > 0);
}
