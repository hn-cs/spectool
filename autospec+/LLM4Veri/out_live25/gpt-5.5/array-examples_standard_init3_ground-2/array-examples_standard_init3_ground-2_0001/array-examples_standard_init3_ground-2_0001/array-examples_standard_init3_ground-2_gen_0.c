#include <assert.h>
#define N 100000
int main ( ) {
  int a[N];
  int i = 0;
  /*@
  loop invariant 0 <= i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] == 42;
  loop assigns i, a[0..N-1];
  loop variant N - i;
  */
  while ( i < N ) {
    a[i] = 42;
    i = i + 1;
  }
  i = 0;
  while ( i < N ) {
    a[i] = 43;
    i = i + 1;
  }
  i = 0;
  while ( i < N ) {
    a[i] = 44;
    i = i + 1;
  }
  int x;
  for ( x = 0 ; x < N ; x++ ) {
    // @ assert(a[x] == 44  );
  }
  return 0;
}
