#include "assert.h"

#define SZ 2048

int main(void) {
  int A[SZ];
  int B[SZ];
  int i;
  int tmp;

  /*@
  loop invariant \forall integer j; i <= j < SZ ==> \at(B[j], Here) == \at(B[j], Pre);
  loop invariant \forall integer j; 0 <= j < i ==> \at(B[j], Here) == \at(A[j], Pre);
  loop invariant \exists integer j; 0 <= j < SZ && A[j] == B[j];
  loop invariant i <= SZ;
  loop invariant \forall integer j; 0 <= j < i ==> B[j] == \at(A[j], Pre);
  loop invariant \forall integer j; 0 <= j < i ==> B[j] == A[j];
  loop invariant \forall integer j; 0 <= j < i ==> A[j] == B[j];
  loop invariant B[i] == B[i];
  loop invariant A[i] == A[i];
  loop invariant A[SZ/2] == A[SZ/2];
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns B[0..SZ-1];
  */
  for (i = 0; i < SZ; i++) {
    tmp = A[i];
    B[i] = tmp;
  }

  // @ assert(A[SZ/2] == B[SZ/2]);
}