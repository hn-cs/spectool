#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define SZ 2048
int main(void) {
  int A[SZ];
  int B[SZ];
  int i;
  int tmp;
  /*@
  loop invariant i <= SZ;
  loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= B[k] < INT_MAX;
  loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= A[k] < INT_MAX;
  loop invariant SZ - i;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns B[0..SZ-1];
  loop assigns A[0..SZ-1];
  */
  for (i = 0; i < SZ; i++) {
    A[i] = unknown();
    B[i] = unknown();
  }
  /*@
  loop invariant 0 <= i <= SZ;
  loop invariant \forall integer k; 0 <= k < i ==> B[k] == A[k];
  loop assigns i;
  loop assigns tmp;
  loop assigns B[0..SZ-1];
  loop variant SZ - i;
  */
  for (i = 0; i < SZ; i++) {
    tmp = A[i];
    B[i] = tmp;
  }
  // @ assert(A[SZ/2] == B[SZ/2]);
}
