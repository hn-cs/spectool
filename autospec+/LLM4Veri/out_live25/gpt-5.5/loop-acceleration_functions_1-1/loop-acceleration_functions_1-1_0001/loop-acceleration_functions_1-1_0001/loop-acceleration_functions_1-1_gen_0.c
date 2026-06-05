/*@
requires z < 0x0fffffff;
assigns \nothing;
ensures \result == z + 2;
ensures \result % 2 == z % 2;
*/
unsigned int f(unsigned int z) {
  return z + 2;
}
int main(void) {
  unsigned int x = 0;
  while (x < 0x0fffffff) {
    x = f(x);
  }
  //@assert(!(x % 2));
}
