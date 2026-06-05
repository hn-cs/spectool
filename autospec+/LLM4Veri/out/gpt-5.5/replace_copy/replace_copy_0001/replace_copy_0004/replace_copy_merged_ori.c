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
  axiomatic Replace
  {
    predicate
    Replace{K,L}(value_type* a, integer n, value_type* b,
                 value_type v, value_type w) =
      \forall integer i; 0 <= i < n  ==>
        \let ai = \at(a[i],K);
        \let bi = \at(b[i],L);
        (ai == v  ==>  bi == w) && (ai != v  ==>  bi == ai) ;
    predicate
    Replace{K,L}(value_type* a, integer n, value_type v, value_type w) =
      Replace{K,L}(a, n, a, v, w);
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
size_type
replace_copy(const value_type* a, size_type n, value_type* b, value_type v,
             value_type w)
{
  /*@
  loop invariant w <= VALUE_TYPE_MAX;
  loop invariant w <= VALUE_TYPE_MAX || v <= VALUE_TYPE_MAX;
  loop invariant w < VALUE_TYPE_MAX;
  loop invariant v <= VALUE_TYPE_MAX;
  loop invariant v < VALUE_TYPE_MAX;
  loop invariant n <= SIZE_TYPE_MAX;
  loop invariant n <= SIZE_TYPE_MAX || w <= VALUE_TYPE_MAX;
  loop invariant n <= SIZE_TYPE_MAX || v <= VALUE_TYPE_MAX;
  loop invariant n <= SIZE_TYPE_MAX || VALUE_TYPE_MIN <= w;
  loop invariant n <= SIZE_TYPE_MAX || VALUE_TYPE_MIN <= v;
  loop invariant n < SIZE_TYPE_MAX;
  loop invariant i <= SIZE_TYPE_MAX;
  loop invariant i <= SIZE_TYPE_MAX || w <= VALUE_TYPE_MAX;
  loop invariant i <= SIZE_TYPE_MAX || v <= VALUE_TYPE_MAX;
  loop invariant i <= SIZE_TYPE_MAX || n <= SIZE_TYPE_MAX;
  loop invariant i <= SIZE_TYPE_MAX || VALUE_TYPE_MIN <= w;
  loop invariant i <= SIZE_TYPE_MAX || VALUE_TYPE_MIN <= v;
  loop invariant i < SIZE_TYPE_MAX;
  loop invariant \separated(a + (0..n-1), b + (0..n-1)) ==> \forall integer k; 0 <= k < i ==> b[k] == (a[k] == v ? w : a[k]);
  loop invariant \separated(a + (0..n-1), b + (0..n-1)) ==> Unchanged{Pre,Here}((value_type*)a, n);
  loop invariant \forall integer k; i <= k < n ==> b[k] == \at(b[k],LoopEntry);
  loop invariant VALUE_TYPE_MIN <= w;
  loop invariant VALUE_TYPE_MIN <= w || w <= VALUE_TYPE_MAX;
  loop invariant VALUE_TYPE_MIN <= w || v <= VALUE_TYPE_MAX;
  loop invariant VALUE_TYPE_MIN <= v;
  loop invariant VALUE_TYPE_MIN <= v || w <= VALUE_TYPE_MAX;
  loop invariant VALUE_TYPE_MIN <= v || v <= VALUE_TYPE_MAX;
  loop invariant VALUE_TYPE_MIN <= v || VALUE_TYPE_MIN <= w;
  loop invariant VALUE_TYPE_MIN < w;
  loop invariant VALUE_TYPE_MIN < v;
  loop invariant w == \at(w,LoopEntry);
  loop invariant v == \at(v,LoopEntry);
  loop invariant n == \at(n,LoopEntry);
  loop invariant i <= n;
  loop invariant i < n ==> i + 1 <= n;
  loop invariant b == \at(b,LoopEntry);
  loop invariant a == \at(a,LoopEntry);
  loop invariant \separated(a + (0..n-1), b + (0..n-1)) ==> \forall integer k; 0 <= k < i ==> (a[k] == v ==> b[k] == w);
  loop invariant \separated(a + (0..n-1), b + (0..n-1)) ==> \forall integer k; 0 <= k < i ==> (a[k] != v ==> b[k] == a[k]);
  loop invariant \separated(a + (0..n-1), b + (0..n-1)) ==> Replace{Pre,Here}(a, i, b, v, w);
  loop invariant Unchanged{Pre,Here}(b, i, n);
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns b[0..n-1];
  */
  for (size_type i = 0u; i < n; ++i) {
    b[i] = (a[i] == v ? w : a[i]);
  }
  // @ assert Replace{Pre,Here}(a, n, b, v, w);
  return n;
}