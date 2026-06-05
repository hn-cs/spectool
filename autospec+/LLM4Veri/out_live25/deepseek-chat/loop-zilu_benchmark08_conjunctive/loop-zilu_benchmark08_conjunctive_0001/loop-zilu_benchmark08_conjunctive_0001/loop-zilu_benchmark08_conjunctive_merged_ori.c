#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
int main() {
  int n = unknown();
  int sum = unknown();
  int i = unknown();
  if (!(n>=0 && sum==0 && i==0)) return 0;
  /*@
  loop invariant sum == (i*(i-1))/2;
  loop invariant n - i;
  loop invariant i <= n;
  loop invariant 0 <= sum;
  loop invariant 0 <= i;
  loop assigns sum;
  loop assigns i;
  */
  while (i<n) {
    sum=sum+i;
    i++;
  }
  // @ assert(sum>=0);
  return 0;
}
