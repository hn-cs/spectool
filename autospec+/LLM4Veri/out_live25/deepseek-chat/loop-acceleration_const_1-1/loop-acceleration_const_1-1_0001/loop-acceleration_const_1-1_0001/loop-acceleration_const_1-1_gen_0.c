int main(void) {
  unsigned int x = 1;
  unsigned int y = 0;
  /*@
  loop invariant 0 <= y <= 1024;
  loop invariant x == 0;
  loop assigns x, y;
  */
  while (y < 1024) {
    x = 0;
    y++;
  }
  // @ assert(x == 0);
}
