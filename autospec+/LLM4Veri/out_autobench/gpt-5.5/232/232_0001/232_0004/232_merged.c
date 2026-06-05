#include "assert.h"

#define SZ 2048

int main(void) {
  int A[SZ];
  int B[SZ];
  int i;
  int tmp;

  /*@
  loop invariant i > 0 ==> tmp == \at(B[i-1],Here);
  loop invariant i > 0 ==> tmp == \at(A[i-1],LoopEntry);
  loop invariant i > 0 ==> tmp == B[i-1];
  loop invariant i == 0 ==> tmp == \at(tmp,LoopEntry);
  loop invariant i < SZ ==> \valid(B + i);
  loop invariant i < SZ ==> \valid(A + i);
  loop invariant \separated(A + (0..SZ-1), B + (0..i-1));
  loop invariant \forall integer k; i <= k < SZ ==> A[k] == \at(A[k],LoopEntry);
  loop invariant \forall integer k; 0 <= k < i ==> \at(B[k],Here) == \at(A[k],LoopEntry);
  loop invariant \forall integer k; 0 <= k < i ==> B[k] == \at(A[k],Here);
  loop invariant i > 0 ==> tmp == A[i-1];
  loop invariant i == SZ || 0 <= i < SZ;
  loop invariant i == 0 || B[i-1] == A[i-1];
  loop invariant i <= SZ;
  loop invariant i < SZ ==> 0 <= i < SZ;
  loop invariant \valid(B + (0..SZ-1));
  loop invariant \valid(A + (0..SZ-1));
  loop invariant \separated(A + (0..SZ-1), B + (0..SZ-1));
  loop invariant \forall integer k; i <= k < SZ ==> B[k] == \at(B[k],LoopEntry);
  loop invariant \forall integer k; 0 <= k < i ==> B[k] == \at(B[k],Here);
  loop invariant \forall integer k; 0 <= k < i ==> B[k] == \at(A[k],LoopEntry);
  loop invariant \forall integer k; 0 <= k < i ==> B[k] == A[k];
  loop invariant \forall integer k; 0 <= k < SZ ==> A[k] == \at(A[k],LoopEntry);
  loop invariant SZ - i;
  loop invariant SZ - i <= SZ;
  loop invariant SZ - i <= SZ || 0 <= SZ - i;
  loop invariant SZ - i < SZ;
  loop invariant 0 <= i;
  loop invariant 0 <= SZ - i;
  loop invariant 0 < SZ - i;
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