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
  int a3[N];
  int i; 
  int z;
  z = 150000;
  /*@
  loop invariant z == 150000;
  loop invariant \forall integer k; i <= k < N ==> a3[k] == \at(a3[k],Pre);
  loop invariant \forall integer k; i <= k < N ==> a2[k] == \at(a2[k],Pre);
  loop invariant \forall integer k; i <= k < N ==> a1[k] == \at(a1[k],Pre);
  loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= a3[k] < INT_MAX;
  loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= a2[k] < INT_MAX;
  loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= a1[k] < INT_MAX;
  loop invariant i <= N;
  loop invariant N - i;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns a3[0..N-1];
  loop assigns a2[0..N-1];
  loop assigns a1[0..N-1];
  */
  for ( i = 0 ; i < N ; i++ ) {
         a1[i] = unknown();
	 a2[i] = unknown();
  	 a3[i] = unknown();
  }
  /*@
  loop invariant z == 150000;
  loop invariant i <= N;
  loop invariant \forall integer k; i <= k < N ==> a3[k] == \at(a3[k],Pre);
  loop invariant \forall integer k; i <= k < N ==> a1[k] == \at(a1[k],Pre);
  loop invariant \forall integer k; 0 <= k < i && k != z ==> a2[k] == a1[k];
  loop invariant N - i;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns a2[0..N-1];
  */
  for ( i = 0 ; i < N ; i++ ) {
      if (i != z)
         a2[i] = a1[i];
  }
  /*@
  loop invariant z == 150000;
  loop invariant i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> a3[k] == a1[k];
  loop invariant \forall integer k; 0 <= k < N && k != z ==> a2[k] == a1[k];
  loop invariant N - i;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns a3[0..N-1];
  */
  for ( i = 0 ; i < N ; i++ ) {
      if (i != z)
         a3[i] = a2[i];
      else
          a3[i] = a1[i];
  }
  int x;
  /*@
  loop invariant z == 150000;
  loop invariant x <= N;
  loop invariant \forall integer k; 0 <= k < N ==> a3[k] == a1[k];
  loop invariant N - x;
  loop invariant 0 <= x;
  loop assigns x;
  */
  for ( x = 0 ; x < N ; x++ ) {
    // @ assert(a1[x] == a3[x]  );
  }
  return 0;
}
