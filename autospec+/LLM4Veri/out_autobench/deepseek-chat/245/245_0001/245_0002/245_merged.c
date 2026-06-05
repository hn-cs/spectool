#include <limits.h>
/*@
    ensures \result > 0 && \result <= INT_MAX;
*/
int unknown_int();

int main() {
  int i,k,n,l;

  n = unknown_int();
  l = unknown_int();
  /*@
  loop invariant l <= n;
  loop invariant k <= n;
  loop invariant \forall integer j; 0 <= j < k-1 ==> \at(l, Pre) <= \at(l, Here);
  loop invariant 1 <= k;
  loop invariant 0 <= l;
  loop assigns l;
  loop assigns k;
  loop assigns i;
  */
  for (k=1;k<n;k++){
    /*@
    loop invariant n - k;
    loop invariant l <= n ==> i >= l;
    loop invariant k <= n;
    loop invariant \forall integer j; k <= j < n ==> \at(i, Here) == l;
    loop invariant 0 <= l;
    loop invariant 0 <= k;
    loop assigns i;
    */
    for (i=l;i<n;i++){  
      //@ assert(1<=i);
    }
    if(unknown_int())
      l = l + 1;
  }
 }