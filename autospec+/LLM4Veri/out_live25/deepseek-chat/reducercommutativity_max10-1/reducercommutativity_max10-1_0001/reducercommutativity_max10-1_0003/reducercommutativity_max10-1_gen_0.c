#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#define N 10
#define fun max
#include <assert.h>
/*@
requires \valid(x+(0..N-1));
ensures \forall integer i; 0 <= i < N ==> \result >= x[i];
ensures \forall integer i; 0 <= i < N ==> \exists integer j; 0 <= j < N && \result == x[j];
*/
int max (int x[N])
{
  int i;
  long long ret;
  ret = 0;
  /*@
  loop invariant i <= N;
  loop invariant \forall integer j; 0 <= j < i ==> ret >= x[j];
  loop invariant \forall integer j; 0 <= j < i ==> ret >= (long long)x[j];
  loop invariant 0 <= i;
  loop assigns ret;
  loop assigns i;
  */
  for (i = 0; i < N; i++) {
    ret = ret < x[i] ? x[i] : ret;
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
  loop invariant 0 <= i <= N;
  loop invariant \forall integer j; 0 <= j < i ==> INT_MIN <= x[j] <= INT_MAX;
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
  for(int i =0 ; i<N-1; i++){
     x[i] = x[i+1];
  }
  x[N-1] = temp;
  ret5 = fun(x);
  // @ assert !(ret != ret2 || ret !=ret5);
  return 1;
}
