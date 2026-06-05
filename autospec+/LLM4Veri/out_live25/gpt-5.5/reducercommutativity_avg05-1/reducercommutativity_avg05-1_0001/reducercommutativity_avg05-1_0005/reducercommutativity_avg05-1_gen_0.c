#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#define N 5
#define fun avg
#include <assert.h>
int avg (int x[N])
{
  int i;
  long long ret;
  ret = 0;
  /*@
  loop invariant ret == \sum integer k; 0 <= k < i; (long long)x[k];
  loop invariant (long long)i * INT_MIN <= ret <= (long long)i * INT_MAX;
  loop invariant \forall integer k; 0 <= k < N ==> x[k] == \at(x[k], LoopEntry);
  loop invariant N == 5;
  loop invariant 0 <= N - i;
  loop invariant i <= N;
  loop invariant 0 <= i;
  loop assigns ret;
  loop assigns i;
  */
  for (i = 0; i < N; i++) {
    ret = ret + x[i];
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
  loop invariant \forall integer k; 0 <= k < i ==> \initialized(&x[k]);
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
  loop invariant temp == \at(x[0], LoopEntry);
  loop invariant i <= N-1;
  loop invariant \forall integer k; i <= k < N ==> x[k] == \at(x[k], LoopEntry);
  loop invariant \forall integer k; 0 <= k < i ==> x[k] == \at(x[k+1], LoopEntry);
  loop invariant N-1-i;
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
