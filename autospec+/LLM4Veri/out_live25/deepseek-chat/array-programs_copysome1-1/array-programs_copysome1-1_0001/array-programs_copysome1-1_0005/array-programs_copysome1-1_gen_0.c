#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define N 200000
int main( ) {
  int a1[N];
  int a2[N];
  int i; 
  int z;
  z = 150000;
  /*@
  loop invariant i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> a2[k] == a2[k];
  loop invariant \forall integer k; 0 <= k < i ==> a1[k] == a1[k];
  loop invariant \forall integer k; 0 <= k < i && k == z ==> a2[k] == \at(a2[k], Pre);
  loop invariant \forall integer k; 0 <= k < i && k != z ==> a2[k] == a1[k];
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns a2[0..N-1];
  loop assigns a1[0..N-1];
  */
  for ( i = 0 ; i < N ; i++ ) {
         a1[i] = unknown();
	 a2[i] = unknown();
  }
  /*@
  loop invariant i <= N;
  loop invariant \forall integer k; 0 <= k < i && k == z ==> a2[k] == \at(a2[k], Pre);
  loop invariant \forall integer k; 0 <= k < i && k != z ==> a2[k] == a1[k];
  loop invariant 0 <= i;
  loop invariant i <= N;
  loop invariant \forall integer k; 0 <= k < i && k == z ==> a2[k] == \at(a2[k], Pre);
  loop invariant \forall integer k; 0 <= k < i && k != z ==> a2[k] == a1[k];
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns a2[0..N-1];
  */
  for ( i = 0 ; i < N ; i++ ) {
      if (i != z)
         a2[i] = a1[i];
  }
  int x;
  /*@
  loop invariant x <= N;
  loop invariant \forall integer k; 0 <= k < x && k == z ==> a2[k] == \at(a2[k], Pre);
  loop invariant \forall integer k; 0 <= k < x && k != z ==> a1[k] == a2[k];
  loop invariant N - x;
  loop invariant 0 <= x;
  loop assigns x;
  */
  for ( x = 0 ; x < N ; x++ ) {
      if (x != z){
    // @ assert(a1[x] == a2[x]  );
      }
  }
  return 0;
}
