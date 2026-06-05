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
  while (x < 0x0fffffff) {
    x = f(x);
  }
}
