#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define N 100000
int main ( ) {
  int a[N]; int e = unknown();
  int i = 0;
  int j;
  /*@
  loop invariant j <= N;
  loop invariant \forall integer k; j <= k < N ==> a[k] == \at(a[k], Pre);
  loop invariant \forall integer k; 0 <= k < j ==> a[k] == a[k];
  loop invariant 0 <= j;
  loop assigns j;
  loop assigns a[0..N-1];
  */
  for ( j = 0 ; j < N; j++ ) {
    a[j] = unknown();
  }
  /*@
  loop invariant \exists integer k; 0 <= k < i && a[k] == e ==> \false;
  loop invariant (i < N ==> a[i] != e) || (i == N);
  loop invariant i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] != e;
  loop invariant 0 <= i;
  loop assigns i;
  */
  while( i < N && a[i] != e ) {
    i = i + 1;
  }
  int x;
  /*@
  loop invariant x <= i;
  loop invariant \forall integer k; 0 <= k < x ==> a[k] != e;
  loop invariant 0 <= x;
  loop assigns x;
  */
  for ( x = 0 ; x < i ; x++ ) {
    // @ assert(a[x] != e  );
  }
  return 0;
}
