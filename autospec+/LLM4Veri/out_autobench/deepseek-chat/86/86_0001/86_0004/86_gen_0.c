int main() {
  int x = -50;
  int y = 0;
  
  /*@
  loop invariant 0 <= x + 50;
  loop invariant y <= 10;
  loop invariant y <= -x;
  loop invariant 0 <= y;
  loop invariant -50 <= x;
  loop invariant -1 <= y;
  loop invariant -1 < y;
  loop invariant x + y >= -50;
  loop invariant x + y >= -50;
  loop invariant x + y >= -50;
  loop invariant y <= 10 || -1 <= y;
  loop invariant y <= -x || -1 <= y;
  loop invariant 0 <= y;
  loop invariant -50 <= x;
  loop invariant -1 <= y;
  loop invariant -1 < y;
  loop invariant -1 < y;
  loop invariant -1 < y;
  loop invariant -1 < y;
  loop invariant -1 < y;
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
