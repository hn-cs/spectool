#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#define N 100000
#define fun mapsum
#include <assert.h>
/*@
requires \valid(x+(0..N-1));
ensures \result == \sum(0, N-1, \lambda integer i; i + x[i]) + 1;
assigns \nothing;
*/
int mapsum (int x[N])
{
  int i;
  long long ret;
  ret = 0;
  /*@
  loop invariant ret == (long long)(i*i - i)/2 + \sum(0, i-1, x[l]) + 1;
  loop invariant i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> ret == (long long)(k*k + k)/2 + \sum(0, k-1, x[l]) + 1;
  loop invariant N - i;
  loop invariant 0 <= i;
  loop assigns ret;
  loop assigns i;
  */
  for (i = 0; i < N; i++) {
    ret = ret+ i + x[i];
  }
  return ret;
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
  for(int i =0 ; i<N-1; i++){
     x[i] = x[i+1];
  }
  x[N-1] = temp;
  ret5 = fun(x);
  // @ assert !(ret != ret2 || ret !=ret5);
  return 1;
}
