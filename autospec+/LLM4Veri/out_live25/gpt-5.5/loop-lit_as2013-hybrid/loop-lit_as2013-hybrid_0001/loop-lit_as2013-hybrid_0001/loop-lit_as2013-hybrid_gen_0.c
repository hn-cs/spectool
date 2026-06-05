#include <assert.h>
int main() {
  int i = 0;
  while (1) {
    i++;
    int j = 0;
    /*@
    loop invariant 0 <= j <= 10;
    loop invariant 0 <= i <= 10;
    loop assigns j;
    */
    while (j < 10) {
      // @ assert(0 <= i);
      // @ assert(i <= 10);
      j++;
    }
    if (i > 9)
      i = 0;
  }
  return 0;
}
