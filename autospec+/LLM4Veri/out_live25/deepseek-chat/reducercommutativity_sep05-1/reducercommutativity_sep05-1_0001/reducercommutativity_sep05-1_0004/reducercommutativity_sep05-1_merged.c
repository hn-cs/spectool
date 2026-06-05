#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#define N 5
#define fun sep
#include <assert.h>
/*@
requires \valid(x+(0..N-1));
ensures \result == (\num_of_even - \num_of_odd) where \num_of_even == \num_of int i; 0 <= i < N && x[i] % 2 == 0 && \num_of_odd == N - \num_of_even;
assigns \nothing;
*/
int sep (int x[N])
{
  long long ret =0;
  /*@
  loop invariant ret == (\num_of_even - \num_of_odd) where \num_of_even == \num_of int j; 0 <= j < i && x[j]%2==0 && \num_of_odd == i - \num_of_even;
  loop invariant ret <= N;
  loop invariant i <= N;
  loop invariant N - i;
  loop invariant 0 <= i;
  loop invariant -N <= ret;
  loop assigns ret;
  loop assigns i;
  */
  for(int i=0;i<N;i++)
  {
    if(x[i]%2==0)
      ret++;
    else
      ret--;
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
  loop invariant \forall integer k; 0 <= k < i ==> \valid(x + k);
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
  loop invariant x[N-1] == \at(temp, LoopEntry);
  loop invariant i <= N-1;
  loop invariant \forall integer k; 0 <= k < i ==> x[k] == \at(x[k+1], LoopEntry);
  loop invariant N-1 - i;
  loop invariant 0 <= i;
  loop assigns x[0..N-1];
  loop assigns i;
  */
  for(int i =0 ; i<N-1; i++){
     x[i] = x[i+1];
  }
  x[N-1] = temp;
  ret5 = fun(x);
  //@ assert !(ret != ret2 || ret !=ret5);
  return 1;
}
