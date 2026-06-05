int main(void) {
  unsigned int x = 0;
  unsigned int y = 0;
  /*@
  loop invariant 0 <= x <= 0x0fffffff;
  loop invariant y == 10;
  loop assigns x, y;
  */
  while (x < 0x0fffffff) {
    y = 0;
    /*@
    loop invariant y <= 10;
    loop invariant 10 - y;
    loop invariant 0 <= y;
    loop assigns y;
    */
    while (y < 10) {
      y++;
    }
    x++;
  }
  // @ assert(x % 2);
}
