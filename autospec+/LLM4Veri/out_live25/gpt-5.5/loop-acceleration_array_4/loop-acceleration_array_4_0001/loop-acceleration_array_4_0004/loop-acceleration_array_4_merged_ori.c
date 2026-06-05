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
  loop invariant i <= N-1;
  loop invariant i < N;
  loop invariant \valid(A + (0..N-1));
  loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= A[k] < INT_MAX;
  loop invariant \forall integer k; 0 <= k < i ==> A[k] >= INT_MIN;
  loop invariant \forall integer k; 0 <= k < i ==> A[k] <= INT_MAX - 1;
  loop invariant \forall integer k; 0 <= k < i ==> A[k] != INT_MAX;
  loop invariant N-1 - i;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns A[0..N-2];
  */
  for (i = 0; i < N-1; i++) {
    A[i] = unknown();
  }
  A[N-1] = 0;
  /*@
  loop invariant i < N;
  loop invariant \valid(A + i);
  loop invariant \valid(A + (0..N-1));
  loop invariant \forall integer k; 0 <= k < i ==> A[k] < 0 || A[k] > 0;
  loop invariant \exists integer k; i <= k < N && A[k] == 0;
  loop invariant i <= N-1;
  loop invariant \forall integer k; 0 <= k < i ==> A[k] != 0;
  loop invariant N-1-i;
  loop invariant A[N-1] == 0;
  loop invariant 0 <= i;
  loop assigns i;
  */
  for (i = 0; A[i] != 0; i++) {
  }
  // @ assert(i <= N);
}
