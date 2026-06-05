int main() {
  int x = -5000;
  int y = 0;
  
  /*@
  loop invariant x <= 0 || y > 0;
  loop invariant y >= 0;
  loop invariant x >= -5000;
  loop assigns x, y;
  loop variant 5001 - y;
  */
  while ((x < 0)) {
    x  = x + y;
    y  = y + 1;
  }
  // post-condition
  // @ assert(y > 0);
}
