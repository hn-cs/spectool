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
requires \valid_read(x + (0..N-1));
assigns \nothing;
ensures \result ==
  (\numof integer k; 0 <= k < N && x[k] % 2 == 0)
  - (\numof integer k; 0 <= k < N && x[k] % 2 != 0);
*/
int sep (int x[N])
{
  long long ret =0;
  /*@
  loop invariant ret ==;
  loop invariant ret <= i;
  loop invariant i <= N;
  loop invariant N - i;
  loop invariant 0 <= i;
  loop invariant -i <= ret;
  loop assigns ret;
  loop assigns i;
  - (\numof integer k; 0 <= k < i && x[k] % 2 != 0);
  (\numof integer k; 0 <= k < i && x[k] % 2 == 0);
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
