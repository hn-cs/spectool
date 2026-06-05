#define SIZE 1000
#include <assert.h>
int main()
{
  unsigned int array[SIZE];
  unsigned int index;
  /*@
  loop invariant index <= SIZE;
  loop invariant \forall integer k; 0 <= k < index ==> array[k] == (k % 2);
  loop invariant 0 <= index;
  loop assigns index;
  loop assigns array[0..SIZE-1];
  */
  for (index = 0; index < SIZE; index++) {
    array[index] = (index % 2);
  }
  for (index = 0; index < SIZE; index++) {
    if (index % 2 == 0) {
      // @ assert(array[index] == 0);
    } else {
      // @ assert(array[index] != 0);
    }
  }
}
