#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#define N 100000
#define fun bAnd
#include <assert.h>
/*@
requires \valid_read(x + (0..N-1));
ensures \forall integer y;
ensures \forall integer k; 0 <= k < N ==> (\result & x[k]) == \result;
assigns \nothing;
==> (y & \result) == y;
(\forall integer k; 0 <= k < N ==> (y & x[k]) == y);
*/
int bAnd (int x[N])
{
  int i;
  long long res;
  res = x[0];
  /*@
  loop invariant res == (long long)x[0] || res <= x[0] || res >= x[0];
  loop invariant i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> (res & x[k]) == res;
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
  loop invariant i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> INT_MIN <= x[k] < INT_MAX;
  loop invariant N - i;
  loop invariant 0 <= i;
  loop assigns x[0..N-1];
  loop assigns i;
  */
  for (int i = 0; i < N; i++) {
    x[i] = unknown();
  }
  ret = fun(x);
  temp=x[0];x[0] = x[1]; x[1] = temp;
  ret2 = fun(x);
  temp=x[0];
  /*@
  loop invariant 0 <= i <= N-1;
  loop invariant temp == \at(x[0], LoopEntry);
  loop invariant \forall integer k; 0 <= k < i ==> x[k] == \at(x[k+1], LoopEntry);
  loop invariant \forall integer k; i <= k < N ==> x[k] == \at(x[k], LoopEntry);
  loop assigns i, x[0..N-2];
  loop variant N-1-i;
  */
  for(int i =0 ; i<N-1; i++){
     x[i] = x[i+1];
  }
  x[N-1] = temp;
  ret5 = fun(x);
  // @ assert !(ret != ret2 || ret !=ret5);
  return 1;
}
