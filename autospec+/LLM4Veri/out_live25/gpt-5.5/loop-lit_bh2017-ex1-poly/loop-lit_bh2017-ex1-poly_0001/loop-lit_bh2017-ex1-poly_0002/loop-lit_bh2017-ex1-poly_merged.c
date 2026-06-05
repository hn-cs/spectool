#include <assert.h>
int main() {
  int i = 0;
  /*@
  loop invariant i <= 4;
  loop invariant 0 <= i;
  loop assigns i;
  */
  while (i < 4) {
    int j = 0;
    /*@
    loop invariant j <= 4;
    loop invariant j <= 2 * i;
    loop invariant j % 2 == 0;
    loop invariant 2 * i <= j + 6;
    loop invariant 0 <= j;
    loop assigns j;
    loop assigns i;
    */
    while (j < 3) {
      i++;
      j += 2;
      //@ assert(0 <= j);
      //@ assert(j <= 2 * i);
      //@ assert(2 * i <= j + 6);
      //@ assert(j <= 4);
    }
    //@ assert(0 <= j);
    //@ assert(j <= 2 * i);
    //@ assert(2 * i <= j + 6);
    //@ assert(j <= 4);
    i = i - j / 2 + 1;
  }
  return 0;
}
