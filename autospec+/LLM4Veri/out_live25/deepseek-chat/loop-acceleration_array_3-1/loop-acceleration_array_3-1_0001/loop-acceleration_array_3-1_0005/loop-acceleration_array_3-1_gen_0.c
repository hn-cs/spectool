#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#define N 1024
int main(void) {
  int A[N];
  int i;
  /*@
  loop invariant \forall integer j; 0 <= j < i ==> A[j] != 0;
  loop invariant i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> A[k] != 0;
  loop invariant \exists integer j; 0 <= j < i && A[j] == 0;
  loop invariant i <= N;
  loop invariant \forall integer j; 0 <= j < i ==> A[j] != 0;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns A[0..N-1];
  */
  for (i = 0; i < N; i++) {
    A[i] = unknown();
  }
  /*@
  loop invariant i <= N;
  loop invariant \forall integer j; 0 <= j < i ==> A[j] != 0;
  loop invariant 0 <= i;
  loop assigns i;
  */
  for (i = 0; A[i] != 0; i++) {
    if (i >= N-1) {
      break;
    }
  }
  // @ assert(i <= N);
}
