#include <assert.h>
#define SZ 2048
int main(void) {
  int A[SZ] = {0};
  int B[SZ] = {0};
  int i;
  int tmp;
  /*@
  loop invariant \forall integer k; 0 <= k < SZ ==> A[k] == \at(A[k],LoopEntry);
  loop invariant \forall integer k; 0 <= k < i ==> B[k] == \at(A[k],LoopEntry);
  loop invariant \forall integer k; i <= k < SZ ==> B[k] == \at(B[k],LoopEntry);
  loop invariant \forall integer k; 0 <= k < i ==> B[k] == \at(B[k],LoopEntry);
  loop invariant \forall integer k; 0 <= k < SZ ==> A[k] == \at(B[k],LoopEntry);
  loop invariant i <= SZ;
  loop invariant \valid(B + (0..SZ-1));
  loop invariant \valid(A + (0..SZ-1));
  loop invariant \separated(A + (0..SZ-1), B + (0..SZ-1));
  loop invariant \forall integer k; i <= k < SZ ==> B[k] == 0;
  loop invariant \forall integer k; i <= k < SZ ==> A[k] == B[k];
  loop invariant \forall integer k; 0 <= k < i ==> B[k] == A[k];
  loop invariant \forall integer k; 0 <= k < i ==> B[k] == 0;
  loop invariant \forall integer k; 0 <= k < i ==> A[k] == 0;
  loop invariant \forall integer k; 0 <= k < SZ ==> B[k] == A[k];
  loop invariant \forall integer k; 0 <= k < SZ ==> A[k] == 0;
  loop invariant SZ - i;
  loop invariant 0 <= i;
  loop assigns tmp;
  loop assigns i;
  loop assigns B[0..SZ-1];
  */
  for (i = 0; i < SZ; i++) {
    tmp = A[i];
    B[i] = tmp;
  }
  // @ assert(A[SZ/2] == B[SZ/2]);
}
