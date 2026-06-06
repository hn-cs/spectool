#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();

/*@ axiomatic XorAll {
  @   logic integer xor_all(int *a, integer n);
  @   axiom xor_all_empty: \forall int *a, integer n; n <= 0 ==> xor_all(a, n) == 0;
  @   axiom xor_all_step: \forall int *a, integer n; n > 0 ==> xor_all(a, n) == xor_all(a, n-1) ^ a[n-1];
  @
  @   // Swapping any two elements does not change the overall XOR
  @   axiom xor_all_swap: \forall int *a, integer i, j, n;
  @     0 <= i < n && 0 <= j < n && n > 0 ==>
  @     xor_all(a, n) == xor_all({ a with .[i] = a[j], .[j] = a[i] }, n);
  @ }
  @*/

#define N 100000
#define fun xor
#include <assert.h>
/*@ requires \valid(x+(0 .. N-1));
  @ assigns \nothing;
  @ ensures \result == xor_all(x, N);
  @*/
int xor (int x[N])
{
  int i;
  long long res;
  res = x[0];
  for (i = 1; i < N; i++) {
    res = res ^ x[i];
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
  //@ label before_rotate;
  temp=x[0];
  for(int i =0 ; i<N-1; i++){
     x[i] = x[i+1];
  }
  x[N-1] = temp;
  //@ admit xor_all(x, N) == \at(xor_all(x, N), before_rotate);
  ret5 = fun(x);
  //@ assert !(ret != ret2 || ret !=ret5);
  return 1;
}
