int main() {
  int x = -50;
  int y = 0;
  
  /*@
  loop invariant y <= -x;
  loop invariant y >= -1;
  loop invariant x + y * (y - 1) / 2 == -50;
  loop invariant y <= 10;
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
