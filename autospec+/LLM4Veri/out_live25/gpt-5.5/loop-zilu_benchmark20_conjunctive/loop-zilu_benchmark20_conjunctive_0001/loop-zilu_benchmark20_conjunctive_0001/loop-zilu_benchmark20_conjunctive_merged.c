#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
int main() {
  int i = unknown();
  int n = unknown();
  int sum = unknown();
  if (!(i==0 && n>=0 && n<=100 && sum==0)) return 0;
  /*@
  loop invariant n <= 100;
  loop invariant i <= n;
  loop invariant 0 <= sum;
  loop invariant 0 <= i;
  loop assigns sum;
  loop assigns i;
  */
  while (i<n) {
    sum = sum + i;
    i++;
  }
  //@ assert(sum>=0);
  return 0;
}
