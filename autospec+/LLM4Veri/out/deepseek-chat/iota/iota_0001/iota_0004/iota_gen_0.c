#include <limits.h>
#ifndef __cplusplus
typedef int bool;
#define false		((bool)0)
#define true		((bool)1)
#endif
typedef int value_type;
#define VALUE_TYPE_MAX  INT_MAX
#define VALUE_TYPE_MIN  INT_MIN
typedef unsigned int size_type;
#define SIZE_TYPE_MAX  UINT_MAX
/*@
  axiomatic IotaGenerate
  {
    predicate
    IotaGenerate(value_type* a, integer n, value_type v) =
      \forall integer i; 0 <= i < n  ==>  a[i] == v+i;
  }
*/
void
/*@
requires \valid(a+(0..n-1));
requires n <= VALUE_TYPE_MAX - v + 1; // prevent overflow when v increases
ensures IotaGenerate(a, n, v);
assigns a[0..n-1];
*/
iota(value_type* a, size_type n, value_type v)
{
  /*@
  loop invariant i <= n;
  loop invariant \forall integer k; i <= k < n ==> a[k] == 0;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] == v -(n - i) + k;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] == v + k;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] == (v_at_loop_entry + k);
  loop invariant IotaGenerate(a, i, v - (n - i));
  loop invariant 0u <= i;
  loop assigns i;
  loop assigns a[0..n-1];
  */
  for (size_type i = 0u; i < n; ++i) {
    a[i] = v++;
  }
}
int main(){
    value_type a[10];
    iota(a, 10, 1);
    // @ assert \forall integer i; 0 <= i < 10 ==> a[i] == i + 1;
    return 0;
}