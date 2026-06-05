#define SIZE 10000
#include <assert.h>
int main()
{
  unsigned int array[SIZE];
  unsigned int index = 0;
  unsigned int tmp = 0;
  /*@
  loop invariant tmp == 2 * index;
  loop invariant index <= SIZE;
  loop invariant \forall integer i; 0 <= i < index ==> array[i] == 2 * i;
  loop invariant SIZE - index;
  loop invariant 0 <= index;
  loop assigns tmp;
  loop assigns index;
  loop assigns array[0..SIZE-1];
  */
  while (index < SIZE) {
    array[index] = tmp;
    index = index + 1;
    tmp = tmp + 2;
  }
  for (index = 0; index < SIZE; index++) {
     // @ assert((array[index] == 2*index) || (array[index] == 0));
  }
}
