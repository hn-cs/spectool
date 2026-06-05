/*@
requires z < 0x0fffffff;
ensures \result == z + 2;
ensures \result % 2 == z % 2;
assigns \nothing;
*/
unsigned int f(unsigned int z) {
  return z + 2;
}
int main(void) {
  unsigned int x = 0;
  /*@
  loop invariant x <= 0x10000000;
  loop invariant x % 2 == 0;
  loop assigns x;
  loop variant 0x10000000 - x;
  */
  while (x < 0x0fffffff) {
    x = f(x);
  }
  //@assert(!(x % 2));
}
