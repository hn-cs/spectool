int main() {
  unsigned int x = 0;
  /*@
  loop invariant 0 <= x;
  loop invariant (x < 10000000) || (x >= 10000000);
  loop assigns x;
  */
  while (x < 100000000) {
    if (x < 10000000) {
      x++;
    } else {
      x += 2;
    }
  }
  return 0;
}
