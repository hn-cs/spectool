#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#define N 1000
#define fun bor
#include <assert.h>
/*@
  axiomatic OrFold {
    logic integer or_fold{L}(int *a, integer start, integer end);
    axiom or_fold_empty{L}: \forall int *a, integer s, e; s >= e ==> or_fold(a, s, e) == 0;
    axiom or_fold_step{L}: \forall int *a, integer s, e; s < e ==> or_fold(a, s, e) == a[s] | or_fold(a, s+1, e);
  }
*/
int bor (int x[N])
{
  int i;
  long long res;
  res = x[0];
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
  //@ assert !(ret != ret2 || ret !=ret5);
  return 1;
}
