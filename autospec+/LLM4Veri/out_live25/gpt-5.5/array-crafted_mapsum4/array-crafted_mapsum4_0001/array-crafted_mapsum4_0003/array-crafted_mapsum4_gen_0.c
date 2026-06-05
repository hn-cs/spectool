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
requires \valid_read(x + (0..N-1));
ensures \result == \sum integer k; 0 <= k < N; k + x[k];
assigns \nothing;
*/
int mapsum (int x[N])
{
  int i;
  long long ret;
  ret = 0;
  /*@
  loop invariant ret == \sum integer k; 0 <= k < i; (long long)k + (long long)x[k];
  loop invariant i <= N;
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
