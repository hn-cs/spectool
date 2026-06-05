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
  loop invariant i <= N;
  loop invariant \valid(A+(0..N-1));
  loop invariant \forall integer k; i <= k < N ==> \valid(A+k);
  loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= A[k] < INT_MAX;
  loop invariant \forall integer k; 0 <= k < i ==> A[k] >= INT_MIN;
  loop invariant \forall integer k; 0 <= k < i ==> A[k] <= INT_MAX - 1;
  loop invariant \forall integer k; 0 <= k < i ==> A[k] < INT_MAX;
  loop invariant N - i;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns A[0..N-1];
  */
  for (i = 0; i < N; i++) {
    A[i] = unknown();
  }
  /*@
  loop invariant i <= N-1;
  loop invariant \valid(A+(0..N-1));
  loop invariant \forall integer k; 0 <= k < N ==> INT_MIN <= A[k] < INT_MAX;
  loop invariant \forall integer k; 0 <= k < i ==> A[k] < 0 || A[k] > 0;
  loop invariant i > 0 ==> \exists integer k; 0 <= k < i && A[k] != 0;
  loop invariant i < N;
  loop invariant \forall integer k; 0 <= k < i ==> A[k] != 0;
  loop invariant N - 1 - i;
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
