#include <assert.h>
#define N 100000
int main ( ) {
  int a[N];
  int i = 0;
  /*@
  loop invariant \forall integer k; i <= k < N ==> a[k] == \at(a[k],Pre);
  loop invariant i == 0 ==> \forall integer k; 0 <= k < N ==> a[k] == \at(a[k],Pre);
  loop invariant 0 <= i <= N;
  loop invariant i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] == 42;
  loop invariant N - i;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns a[0..N-1];
  */
  while ( i < N ) {
    a[i] = 42;
    i = i + 1;
  }
  i = 0;
  /*@
  loop invariant i <= N;
  loop invariant \forall integer k; i <= k < N ==> a[k] == 42;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] == 43;
  loop invariant N - i;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns a[0..N-1];
  */
  while ( i < N ) {
    a[i] = 43;
    i = i + 1;
  }
  i = 0;
  /*@
  loop invariant i <= N;
  loop invariant \forall integer k; i <= k < N ==> a[k] == 43;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] == 44;
  loop invariant N - i;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns a[0..N-1];
  */
  while ( i < N ) {
    a[i] = 44;
    i = i + 1;
  }
  int x;
  /*@
  loop invariant x <= N;
  loop invariant \forall integer k; 0 <= k < N ==> a[k] == 44;
  loop invariant N - x;
  loop invariant 0 <= x;
  loop assigns x;
  */
  for ( x = 0 ; x < N ; x++ ) {
    // @ assert(a[x] == 44  );
  }
  return 0;
}
