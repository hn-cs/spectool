#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#define N 5
#define fun max
#include <assert.h>
int max (int x[N])
{
  int i;
  long long ret;
  ret = 0;
  /*@
  loop invariant 0 <= i <= N;
  loop invariant ret == (0 <= i ? (x[0] >= x[1] ? x[0] : x[1]) : 0);
  loop invariant \forall integer k; 0 <= k < i ==> ret >= x[k];
  loop assigns ret, i;
  loop variant N - i;
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
