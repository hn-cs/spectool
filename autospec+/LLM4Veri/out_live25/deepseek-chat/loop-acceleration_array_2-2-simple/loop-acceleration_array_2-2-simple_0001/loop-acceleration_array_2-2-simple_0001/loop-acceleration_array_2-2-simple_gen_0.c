#include <assert.h>
#define SZ 2048
int main(void) {
  int A[SZ] = {0};
  int B[SZ] = {0};
  int i;
  int tmp;
  /*@
  loop invariant 0 <= i <= SZ;
  loop invariant \forall integer k; 0 <= k < i ==> A[k] == B[k];
  loop assigns B[0..SZ-1], i, tmp;
  */
  for (i = 0; i < SZ; i++) {
    tmp = A[i];
    B[i] = tmp;
  }
  // @ assert(A[SZ/2] == B[SZ/2]);
}
