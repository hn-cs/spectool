#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define N 100000
int main( ) {
  int a1[N];
  int a2[N];
  int a;
  /*@
  loop invariant 0 <= a <= N;
  loop invariant \forall integer k; 0 <= k < a ==> a1[k] <= INT_MAX;
  loop invariant \forall integer k; 0 <= k < a ==> a1[k] >= INT_MIN;
  loop invariant \forall integer k; a <= k < N ==> a1[k] == \at(a1[k],Pre);
  loop invariant \valid(a1 + (0..N-1));
  loop invariant a <= N;
  loop invariant \forall integer k; 0 <= k < a ==> INT_MIN <= a1[k] < INT_MAX;
  loop invariant N - a;
  loop invariant 0 <= a;
  loop assigns a;
  loop assigns a1[0..N-1];
  */
  for ( a = 0 ; a < N ; a++ ) {
      a1[a] = unknown();
  }
  int i;
  /*@
  loop invariant i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> a2[k] == a1[k];
  loop invariant \forall integer k; 0 <= k < N ==> INT_MIN <= a1[k] < INT_MAX;
  loop invariant N - i;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns a2[0..N-1];
  */
  for ( i = 0 ; i < N ; i++ ) {
    a2[i] = a1[i];
  }
  int x;
  /*@
  loop invariant x <= N;
  loop invariant \forall integer k; 0 <= k < N ==> a2[k] == a1[k];
  loop invariant \forall integer k; 0 <= k < N ==> INT_MIN <= a1[k] < INT_MAX;
  loop invariant N - x;
  loop invariant 0 <= x;
  loop assigns x;
  */
  for ( x = 0 ; x < N ; x++ ) {
    // @ assert(a1[x] == a2[x]  );
  }
  return 0;
}
