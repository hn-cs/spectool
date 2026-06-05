int main() {
  int x = -15000;
  int y = 0;
  
  /*@
  loop invariant x <= 0;
  loop invariant 0 <= y;
  loop invariant x + y*(y-1)/2 == -15000;
  loop assigns x, y;
  */
  while (x < 0) {
    x  = x + y;
    y  = y + 1;
  }
  // post-condition
  // @ assert(y > 0);
}
