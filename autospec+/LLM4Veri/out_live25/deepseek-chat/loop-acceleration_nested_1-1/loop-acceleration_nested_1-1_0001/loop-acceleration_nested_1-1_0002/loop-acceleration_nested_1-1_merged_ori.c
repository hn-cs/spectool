int main(void) {
  unsigned int x = 0;
  unsigned int y = 0;
  /*@
  loop invariant y == 10;
  loop invariant x <= 0x0fffffff;
  loop invariant 0 <= x;
  loop assigns y;
  loop assigns x;
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
