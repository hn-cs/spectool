#include <assert.h>
#define SZ 2048
int main(void) {
  int A[SZ] = {0};
  int B[SZ] = {0};
  int i;
  int tmp;
  /*@
  loop invariant i == \at(i, Pre) + 1;
  loop invariant \forall integer k; 0 <= k<i ==> B[k] == A[k];
  loop invariant \forall integer k; 0 <= k<i ==> A[k] == B[k];
  loop invariant \forall integer k; 0 <= k < i ==> B[k] == A[k];
  loop invariant i == \old(i) + 1;
  loop invariant i <= SZ;
  loop invariant \forall integer k; 0 <= k < i ==> A[k] == B[k];
  loop invariant \forall integer j; 0 <= j < i ==> A[j] == B[j];
  loop invariant 0 <= i;
  loop assigns tmp;
  loop assigns i;
  loop assigns B[0..SZ-1];
  */
  for (i = 0; i < SZ; i++) {
    tmp = A[i];
    B[i] = tmp;
  }
  //@ assert(A[SZ/2] == B[SZ/2]);
}
