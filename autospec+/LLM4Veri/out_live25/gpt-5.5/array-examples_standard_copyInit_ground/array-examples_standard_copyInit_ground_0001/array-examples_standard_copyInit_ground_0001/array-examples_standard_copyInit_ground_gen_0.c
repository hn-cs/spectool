#include <assert.h>
#define N 100000
int main ( ) {
  int a [N];
  int b [N]; 
  int i = 0;
  /*@
  loop invariant 0 <= i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] == 42;
  loop assigns i;
  loop assigns a[0..N-1];
  loop variant N - i;
  */
  while ( i < N ) {
    a[i] = 42;
    i = i + 1;
  }
  for ( i = 0 ; i < N ; i++ ) {
    b[i] = a[i];
  }
  int x;
  for ( x = 0 ; x < N ; x++ ) {
    // @ assert(b[x] == 42  );
  }
  return 0;
}
