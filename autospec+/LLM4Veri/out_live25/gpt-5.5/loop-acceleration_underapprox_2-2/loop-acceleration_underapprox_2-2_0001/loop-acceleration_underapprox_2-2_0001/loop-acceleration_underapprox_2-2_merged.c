int main(void) {
  unsigned int x = 0;
  unsigned int y = 1;
  /*@
  loop invariant y == (1u << x);
  loop invariant x <= 6;
  loop invariant 0 <= x;
  loop assigns y;
  loop assigns x;
  */
  while (x < 6) {
    x++;
    y *= 2;
  }
  //@ assert(x == 6);
}
