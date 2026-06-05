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
  loop invariant 0 <= i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= A[k] < INT_MAX;
  loop assigns i, A[0..N-1];
  loop variant N - i;
  */
  for (i = 0; i < N; i++) {
    A[i] = unknown();
  }
  for (i = 0; A[i] != 0; i++) {
    if (i >= N-1) {
      break;
    }
  }
  // @ assert(i <= N);
}
