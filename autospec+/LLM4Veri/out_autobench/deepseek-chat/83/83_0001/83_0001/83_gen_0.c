int main() {
  int x = -5000;
  int y = 0;
  
  /*@
  loop invariant 0 <= x;
  loop invariant y >= 0;
  loop invariant x + y >= 0;
  loop invariant \at(x, Pre) == -5000;
  loop assigns x, y;
  */
  while ((x < 0)) {
    x  = x + y;
    y  = y + 1;
  }
  // post-condition
  // @ assert(y > 0);
}
