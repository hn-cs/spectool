#include <limits.h>
/*@
    ensures \result > 0 && \result <= INT_MAX;
*/
int unknown_int();

int main() {
  int i,k,n,l;

  n = unknown_int();
  l = unknown_int();
  for (k=1;k<n;k++){
    /*@
    loop invariant 0 <= k <= n;
    loop invariant l <= n ==> i >= l;
    loop invariant l >= 0;
    loop invariant \forall integer j; k <= j < n ==> \at(i, Here) == l;
    loop assigns i, k, l;
    loop variant n - k;
    */
    for (i=l;i<n;i++){  
      // @ assert(1<=i);
    }
    if(unknown_int())
      l = l + 1;
  }
 }