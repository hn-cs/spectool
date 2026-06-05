#include <assert.h>
int main() {
  int i = 0;
  while (i < 4) {
    int j = 0;
    /*@
    loop invariant 0 <= j <= 4;
    loop invariant j <= i;
    loop invariant i <= j + 3;
    loop assigns i, j;
    loop variant 4 - j;
    */
    while (j < 4) {
      i++;
      j++;
      // @ assert(0 <= j);
      // @ assert(j <= i);
      // @ assert(i <= j + 3);
      // @ assert(j <= 4);
    }
    // @ assert(0 <= j);
    // @ assert(j <= i);
    // @ assert(i <= j + 3);
    // @ assert(j <= 4);
    i = i - j + 1;
  }
  return 0;
}
