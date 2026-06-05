#include <assert.h>
#define SIZE 100000
int main( ) {
  int a[SIZE];
  int i;
  i = 1;
  a[0] = 7;
  /*@
  loop invariant i <= SIZE;
  loop invariant \forall integer j; 0 <= j < i ==> a[j] == 7 + j;
  loop invariant 1 <= i;
  loop assigns i;
  loop assigns a[0..SIZE-1];
  */
  while( i < SIZE ) {
    a[i] = a[i-1] + 1;
    i = i + 1;
  }
  int x;
  /*@
  loop invariant x < SIZE;
  loop invariant \forall integer k; 0 <= k < x ==> a[k] == a[k] + 0;
  loop invariant 0 <= x;
  loop invariant x <= SIZE;
  loop invariant \forall integer k; 0 <= k < x ==> a[k] == 7 + k;
  loop invariant 1 <= x;
  loop assigns x;
  */
  for ( x = 1 ; x < SIZE ; x++ ) {
    // @ assert(a[x] >= a[x-1]  );
  }
  return 0;
}
