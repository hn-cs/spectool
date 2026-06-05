int main() {
  int x = -15000;
  int y = 0;
  
  /*@
  loop invariant x == -15000 + (y * (y - 1)) / 2;
  loop invariant y <= 174;
  loop invariant x <= y;
  loop invariant y == 0 ==> x == -15000;
  loop invariant 0 <= y;
  loop invariant -15000 <= x;
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
