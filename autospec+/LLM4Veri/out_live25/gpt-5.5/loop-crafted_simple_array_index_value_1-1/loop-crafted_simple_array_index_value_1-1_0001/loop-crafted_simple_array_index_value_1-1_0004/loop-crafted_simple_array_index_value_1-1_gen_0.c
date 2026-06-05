#define SIZE 1000
#include <assert.h>
int main()
{
  unsigned int array[SIZE];
  unsigned int index;
  /*@
  loop invariant index <= SIZE;
  loop invariant index < SIZE ==> index + 1 <= SIZE;
  loop invariant \forall integer k; 0 <= k < index ==> array[k] == k % 2;
  loop invariant \forall integer k; 0 <= k < index ==> array[k] <= 1;
  loop invariant \forall integer k; 0 <= k < index && k % 2 == 1 ==> array[k] == 1;
  loop invariant \forall integer k; 0 <= k < index && k % 2 == 0 ==> array[k] == 0;
  loop invariant SIZE - index;
  loop invariant 0 <= index;
  loop assigns index;
  loop assigns array[0..SIZE-1];
  */
  for (index = 0; index < SIZE; index++) {
    array[index] = (index % 2);
  }
  /*@
  loop invariant index < SIZE ==> index + 1 <= SIZE;
  loop invariant \forall integer k; 0 <= k < SIZE ==> array[k] <= 1;
  loop invariant \forall integer k; 0 <= k < SIZE && k % 2 == 0 ==> array[k] == 0;
  loop invariant \forall integer k; 0 <= k < SIZE && k % 2 == 1 ==> array[k] == 1;
  loop invariant \forall integer k; 0 <= k < index ==> array[k] == k % 2;
  loop invariant \forall integer k; index <= k < SIZE ==> array[k] == k % 2;
  loop invariant index <= SIZE;
  loop invariant \forall integer k; 0 <= k < SIZE ==> array[k] == k % 2;
  loop invariant SIZE - index;
  loop invariant 0 <= index;
  loop assigns index;
  */
  for (index = 0; index < SIZE; index++) {
    if (index % 2 == 0) {
      // @ assert(array[index] == 0);
    } else {
      // @ assert(array[index] != 0);
    }
  }
}
