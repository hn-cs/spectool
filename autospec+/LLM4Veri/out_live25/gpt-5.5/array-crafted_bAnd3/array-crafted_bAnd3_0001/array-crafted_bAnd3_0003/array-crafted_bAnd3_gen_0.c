#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#define N 10000
#define fun bAnd
#include <assert.h>
/*@
requires \valid_read(x + (0..N-1));
logic integer bAnd_range{L}(int *x, integer n) reads x[0..n-1];
ensures \result == bAnd_range(x, N);
axiomatic BAnd {;
axiom bAnd_range_succ{L}:;
axiom bAnd_range_one{L}:;
assigns \nothing;
\forall int *x; bAnd_range(x, 1) == x[0];
\forall int *x, integer n;
1 <= n < N ==> bAnd_range(x, n + 1) == (bAnd_range(x, n) & x[n]);
*/
int bAnd (int x[N])
{
  int i;
  long long res;
  res = x[0];
  /*@
  loop invariant i <= N;
  loop invariant 1 <= i;
  loop assigns res;
  loop assigns i;
  */
  for (i = 1; i < N; i++) {
    res = res & x[i];
  }
  return res;
}
int main ()
{
  int x[N];
  int temp;
  int ret;
  int ret2;
  int ret5;
  /*@
  loop invariant 0 <= i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= x[k] < INT_MAX;
  loop assigns i, x[0..N-1];
  loop variant N - i;
  */
  for (int i = 0; i < N; i++) {
    x[i] = unknown();
  }
  ret = fun(x);
  temp=x[0];x[0] = x[1]; x[1] = temp;
  ret2 = fun(x);
  temp=x[0];
  for(int i =0 ; i<N-1; i++){
     x[i] = x[i+1];
  }
  x[N-1] = temp;
  ret5 = fun(x);
  // @ assert !(ret != ret2 || ret !=ret5);
  return 1;
}
