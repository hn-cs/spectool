#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#define N 100000
#define fun mapavg
#include <assert.h>
int mapavg (int x[N])
{
  int i;
  long long ret;
  ret = 0;
  /*@
  loop invariant x[N-1] == \at(temp, LoopEntry);
  loop invariant \forall integer k; i <= k < N-1 ==> x[k] == \at(x[k], LoopEntry);
  loop invariant \forall integer k; 0 <= k < i ==> x[k] == \at(x[k+1], LoopEntry);
  loop invariant ret == \sum(0 <= k < i; (k + x[k]));
  loop invariant i <= N;
  loop invariant 0 <= i;
  loop assigns ret;
  loop assigns i;
  */
  for (i = 0; i < N; i++) {
    ret = ret+ i + x[i];
  }
  return ret / N;
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
  loop invariant \forall integer j; 0 <= j < i ==> \min(Integer.MIN_VALUE, \max(Integer.MAX_VALUE, x[j])) == \old(x[j]);
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
  loop invariant x[N-1] == \at(temp, LoopEntry);
  loop invariant i <= N-1;
  loop invariant \forall integer j; i <= j < N-1 ==> x[j] == \at(x[j], LoopEntry);
  loop invariant \forall integer j; 0 <= j < i ==> x[j] == \at(x[j+1], LoopEntry);
  loop invariant 0 <= i;
  loop assigns x[0..N-1];
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
