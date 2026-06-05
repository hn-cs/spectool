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
  requires valid:    \valid(p);
  requires valid:    \valid(q);
  assigns            *p;
  assigns            *q;
  ensures  exchange: *p == \old(*q);
  ensures  exchange: *q == \old(*p);
*/
void
swap(value_type* p, value_type* q);
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
void
reverse(value_type* a, size_type n)
{
  const size_type half = n / 2u;
  //@ assert half: half <= n - half;
  //@ assert half: 2*half <= n <= 2*half + 1;
  /*@
  loop invariant \forall integer k; 0 <= k < n ==> \exists integer l; 0 <= l < n && a[k] == \at(a[l], Pre);
  loop invariant \forall integer k; 0 <= k < n ==> \exists integer l; 0 <= l < n && \at(a[l], Pre) == a[k];
  loop invariant i <= half;
  loop invariant half - i;
  loop invariant \forall integer k; n-i <= k < n ==> a[k] == \at(a[n-1-k], Pre);
  loop invariant \forall integer k; i <= k < n-i ==> \at(a[k], Here) == \at(a[k], Pre);
  loop invariant \forall integer k; 0 <= k < i ==> a[k] == \at(a[n-1-k], Pre);
  loop invariant Unchanged{Pre,Here}(a, n - i, n);
  loop invariant Unchanged{Pre,Here}(a, i, n - i);
  loop invariant Unchanged{Pre,Here}(a, 0, i);
  loop invariant Reverse{Pre,Here}(a, 0, i, n - i, n);
  loop invariant 0 <= i;
  loop assigns a[0..n-1];
  */
  for (size_type i = 0u; i < half; ++i) {
    swap(&a[i], &a[n - 1u - i]);
  }
  //@ assert Reverse{Pre,Here}(a, n);
}