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
requires \valid(a + (0..n-1));
requires (integer)v + (integer)n <= VALUE_TYPE_MAX;
ensures \forall integer i; 0 <= i < n ==> a[i] == \old(v) + i;
ensures IotaGenerate(a, n, \old(v));
assigns a[0..n-1];
*/
iota(value_type* a, size_type n, value_type v)
{
  /*@
  loop invariant v == \at(v,Pre) + i;
  loop invariant v - i == \at(v,Pre);
  loop invariant n == \at(n,Pre);
  loop invariant i <= n;
  loop invariant a == \at(a,Pre);
  loop invariant \forall integer k; 0 <= k < i ==> a[k] == \at(v,Pre) + k;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] - k == \at(v,Pre);
  loop invariant \forall integer k, l; 0 <= k < l < i ==> a[k] < a[l];
  loop invariant IotaGenerate(a, i, \at(v,Pre));
  loop invariant 0 <= i;
  loop assigns v;
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