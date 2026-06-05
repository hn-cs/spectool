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
  axiomatic SomeNone
  {
    predicate
    SomeEqual{A}(value_type* a, integer m, integer n, value_type v) =
      \exists integer i; m <= i < n && a[i] == v;
    predicate
    SomeEqual{A}(value_type* a, integer n, value_type v) =
      SomeEqual(a, 0, n, v);
    predicate
    NoneEqual(value_type* a, integer m, integer n, value_type v) =
      \forall integer i; m <= i < n  ==>  a[i] != v;
    predicate
    NoneEqual(value_type* a, integer n, value_type v) =
      NoneEqual(a, 0, n, v);
    lemma NotSomeEqual_NoneEqual:
      \forall value_type *a, v, integer m, n;
        !SomeEqual(a, m, n, v)  ==>  NoneEqual(a, m, n, v);
    lemma NoneEqual_NotSomeEqual:
      \forall value_type *a, v, integer m, n;
       NoneEqual(a, m, n, v)   ==>  !SomeEqual(a, m, n, v);
  }
*/
size_type
remove_copy(const value_type *a, size_type n, value_type *b, value_type v)
{
  size_type k = 0u;
  /*@
  loop invariant \forall size_type j; 0 <= j < k ==> b[j] == a[j];
  loop invariant \forall integer j; 0 <= j < i ==> (a[j] != v ==> \exists integer m; 0 <= m < k && b[m] == a[j]);
  loop invariant k <= i;
  loop invariant i <= n;
  loop invariant \forall size_type j; 0 <= j < k ==> b[j] == a[\at(j,Here)]; // This is tricky - we need to relate b to original a;
  loop invariant \forall size_type j; 0 <= j < k ==> b[j] != v;
  loop invariant \forall size_type j; 0 <= j < i ==> (a[j] != v ==> \exists size_type l; 0 <= l < k && b[l] == a[j]);
  loop invariant \forall integer t; 0 <= t < k ==> b[t] == \at(a[t], Pre);
  loop invariant \forall integer t; 0 <= t < k ==> b[t] != v;
  loop invariant \forall integer t; 0 <= t < i ==> \at(a[t], Pre) != v ==> \exists integer s; 0 <= s < k && b[s] == \at(a[t], Pre);
  loop invariant \exists mapping; // Better approach: use a label;
  loop invariant 0 <= k;
  loop invariant 0 <= i;
  loop assigns k;
  loop assigns i;
  loop assigns b[0..n-1];
  */
  for (size_type i = 0u; i < n; ++i) {
    if (a[i] != v) {
      b[k++] = a[i];
    }
  }
  //@ assert NoneEqual(b, k, v);
  return k;
}