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
  axiomatic Reverse
  {
    predicate
    Reverse{K,L}(value_type* a, integer n, value_type* b) =
      \forall integer i; 0 <= i < n  ==>  \at(a[i],K) == \at(b[n-1-i], L);
    predicate
    Reverse{K,L}(value_type* a, integer m, integer n,
                 value_type* b, integer p) = Reverse{K,L}(a+m, n-m, b+p);
    predicate
    Reverse{K,L}(value_type* a, integer m, integer n, value_type* b) =
      Reverse{K,L}(a, m, n, b, m);
    predicate
    Reverse{K,L}(value_type* a, integer m, integer n, integer p) =
      Reverse{K,L}(a, m, n, a, p);
    predicate
    Reverse{K,L}(value_type* a, integer m, integer n) =
      Reverse{K,L}(a, m, n, m);
    predicate
    Reverse{K,L}(value_type* a, integer n) = Reverse{K,L}(a, 0, n);
  }
*/
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
void
reverse_copy(const value_type* a, size_type n, value_type* b)
{
  /*@
  loop invariant n - i <= n;
  loop invariant n - i < n;
  loop invariant i <= n;
  loop invariant \forall integer k; n-i <= k < n ==> b[k] == a[n-1-k];
  loop invariant \forall integer k; i <= k < n ==> b[k] == \at(b[k], Pre);
  loop invariant \forall integer k; 0 <= k < i ==> b[k] == a[n-1-k];
  loop invariant \forall integer k; 0 <= k < i ==> b[k] == \at(b[k], Pre);
  loop invariant Unchanged{Pre,Here}(b, 0, i);
  loop invariant Reverse{Pre,Here}(a, i, n, b, 0);
  loop invariant Reverse{Pre,Here}(a, i, b, n-i);
  loop invariant Reverse{Pre,Here}(a, 0, i, b, n-i);
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns b[0..n-1];
  */
  for (size_type i = 0u; i < n; ++i) {
    b[i] = a[n - 1u - i];
  }
  // @ assert Reverse{Pre,Here}(a, n, b);
}