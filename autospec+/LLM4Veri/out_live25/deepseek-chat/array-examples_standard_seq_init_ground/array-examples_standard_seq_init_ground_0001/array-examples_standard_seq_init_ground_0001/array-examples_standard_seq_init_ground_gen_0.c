#include <assert.h>
#define SIZE 100000
int main( ) {
  int a[SIZE];
  int i;
  i = 1;
  a[0] = 7;
  /*@
  loop invariant 1 <= i <= SIZE;
  loop invariant \forall integer j; 0 <= j < i ==> a[j] == 7 + j;
  loop assigns i, a[0..SIZE-1];
  */
  while( i < SIZE ) {
    a[i] = a[i-1] + 1;
    i = i + 1;
  }
  int x;
  for ( x = 1 ; x < SIZE ; x++ ) {
    // @ assert(a[x] >= a[x-1]  );
  }
  return 0;
}
