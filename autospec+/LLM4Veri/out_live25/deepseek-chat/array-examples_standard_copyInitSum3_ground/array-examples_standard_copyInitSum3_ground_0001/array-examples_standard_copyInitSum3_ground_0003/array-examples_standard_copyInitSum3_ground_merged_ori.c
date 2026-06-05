#include <assert.h>
#define N 100000
int main ( ) {
  int a [N];
  int b [N]; 
  int i = 0;
  /*@
  loop invariant i <= N;
  loop invariant \forall integer j; 0 <= j < i ==> a[j] == 42;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns a[0..N-1];
  */
  while ( i < N ) {
    a[i] = 42;
    i = i + 1;
  }
  /*@
  loop invariant i <= N;
  loop invariant \forall integer j; 0 <= j < i ==> b[j] == a[j];
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns b[0..N-1];
  */
  for ( i = 0 ; i < N ; i++ ) {
    b[i] = a[i];
  }
  /*@
  loop invariant i <= N;
  loop invariant \forall integer j; 0 <= j < i ==> b[j] == 42 + j;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns b[0..N-1];
  */
  for ( i = 0 ; i < N ; i++ ) {
    b[i] = b[i] + i;
  }
  for ( i = 0 ; i < N ; i++ ) {
    b[i] = b[i] - a[i];
  }
  int x;
  for ( x = 0 ; x < N ; x++ ) {
    // @ assert(b[x] == x  );
  }
  return 0;
}
