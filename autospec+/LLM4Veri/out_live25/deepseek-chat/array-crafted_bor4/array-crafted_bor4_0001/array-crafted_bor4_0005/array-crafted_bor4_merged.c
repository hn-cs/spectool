#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#define N 100000
#define fun bor
#include <assert.h>
int bor (int x[N])
{
  int i;
  long long res;
  res = x[0];
  /*@
  loop invariant res == \old(res) | x[i-1];
  loop invariant res == x[0];
  loop invariant i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> res == x[0] | x[k];
  loop invariant 1 <= i;
  loop assigns res;
  loop assigns i;
  */
  for (i = 1; i < N; i++) {
    res = res | x[i];
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
  loop invariant \forall integer k; 0 <= k < i ==> x[k] == \at(x[k], Pre);
  loop invariant N - i;
  loop invariant 0 <= i;
  loop assigns x[0..N-1];
  */
  for (int i = 0; i < N; i++) {
    x[i] = unknown();
  }
  ret = fun(x);
  temp=x[0];x[0] = x[1]; x[1] = temp;
  ret2 = fun(x);
  temp=x[0];
  /*@
  loop invariant i <= N-1;
  loop invariant \forall integer k; i <= k < N-1 ==> x[k] == \at(x[k], Pre);
  loop invariant \forall integer k; 0 <= k < i ==> x[k] == \at(x[k+1], Pre);
  loop invariant 0 <= i;
  loop assigns x[0..N-2];
  loop assigns i;
  */
  for(int i =0 ; i<N-1; i++){
     x[i] = x[i+1];
  }
  x[N-1] = temp;
  ret5 = fun(x);
  // @ assert !(ret != ret2 || ret !=ret5);
  return 1;
}
