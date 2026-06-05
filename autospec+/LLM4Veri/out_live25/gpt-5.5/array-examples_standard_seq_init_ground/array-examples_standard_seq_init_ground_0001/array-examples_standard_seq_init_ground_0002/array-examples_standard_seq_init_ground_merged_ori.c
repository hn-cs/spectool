#include <assert.h>
#define SIZE 100000
int main( ) {
  int a[SIZE];
  int i;
  i = 1;
  a[0] = 7;
  /*@
  loop invariant i <= SIZE;
  loop invariant a[0] == 7;
  loop invariant \forall integer k; 1 <= k < i ==> a[k] >= a[k-1];
  loop invariant \forall integer k; 1 <= k < i ==> a[k] == a[k-1] + 1;
  loop invariant SIZE - i;
  loop invariant 1 <= i;
  loop assigns i;
  loop assigns a[1..SIZE-1];
  */
  while( i < SIZE ) {
    a[i] = a[i-1] + 1;
    i = i + 1;
  }
  int x;
  /*@
  loop invariant x <= SIZE;
  loop invariant a[0] == 7;
  loop invariant \forall integer k; 1 <= k < x ==> a[k] >= a[k-1];
  loop invariant \forall integer k; 1 <= k < SIZE ==> a[k] >= a[k-1];
  loop invariant \forall integer k; 1 <= k < SIZE ==> a[k] == a[k-1] + 1;
  loop invariant SIZE - x;
  loop invariant 1 <= x;
  loop assigns x;
  */
  for ( x = 1 ; x < SIZE ; x++ ) {
    // @ assert(a[x] >= a[x-1]  );
  }
  return 0;
}
