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
  axiomatic Unchanged
  {
    predicate
    Unchanged{K,L}(value_type* a, integer m, integer n) =
      \forall integer i; m <= i < n ==>  \at(a[i],K) == \at(a[i],L);
    predicate
    Unchanged{K,L}(value_type* a, integer n) = Unchanged{K,L}(a, 0, n);
  }
*/
/*@
  axiomatic Equal
  {
    predicate
    Equal{K,L}(value_type* a, integer m, integer n, value_type* b) =
      \forall integer i; m <= i < n  ==>  \at(a[i],K) == \at(b[i],L);
    predicate
    Equal{K,L}(value_type* a, integer n, value_type* b) =
      Equal{K,L}(a, 0, n, b);
    predicate
    Equal{K,L}(value_type* a, integer m, integer n,
               value_type* b, integer p) = Equal{K,L}(a+m, n-m, b+p);
    predicate
    Equal{K,L}(value_type* a, integer m, integer n, integer p) =
      Equal{K,L}(a, m, n, a, p);
  }
*/
void
copy_backward(const value_type* a, size_type n, value_type* b)
{
  /*@
  loop invariant \forall integer k; i <= k < n ==> b[k] == a[k];
  loop invariant Unchanged{Pre,Here}(a, n);
  loop invariant Unchanged{Here,Pre}(b, i, n);
  loop invariant Unchanged{Here,Pre}(a, 0, i);
  loop invariant Equal{Pre,Here}(b, i, n, b);
  loop invariant i <= n;
  loop invariant \forall integer k; i <= k < n ==> \at(a[k],Pre) == \at(a[k],Pre);
  loop invariant \forall integer k; 0 <= k < i ==> b[k] == \at(b[k],Pre);
  loop invariant \forall integer k; 0 <= k < i ==> \at(a[k],Pre) == \at(a[k],Pre);
  loop invariant 0 <= i;
  */
  for (size_type i = n; i > 0u; --i) {
    b[i - 1u] = a[i - 1u];
  }
  // @ assert Equal{Pre,Here}(a, n, b);
}