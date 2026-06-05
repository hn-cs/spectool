#include <assert.h>
int main() {
  int i = 0;
  /*@
  loop invariant i <= 100;
  loop invariant 0 <= i;
  loop assigns i;
  */
  while (i < 100) {
    int j = 0;
    /*@
    loop invariant j <= 100;
    loop invariant 0 <= j;
    loop assigns j;
    */
    while (j < 100) {
      j++;
      //@ assert(j <= 100);
    }
    //@ assert(j == 100);
    i++;
    //@ assert(i <= 100);
  }
  //@ assert(i == 100);
  return 0;
}
