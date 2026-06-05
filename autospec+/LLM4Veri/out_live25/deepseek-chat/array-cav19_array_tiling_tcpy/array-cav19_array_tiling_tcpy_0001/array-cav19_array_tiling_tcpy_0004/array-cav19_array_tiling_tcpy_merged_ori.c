#include<limits.h>
/*@
assigns \nothing;
ensures 1 < \result < INT_MAX/2;
*/
int unknown();
int main()
{
  int S=unknown();
  // @ assert(S>1);
  // @ assert(S < 1073741823);
  int i;
  int a[2*S];
  int acopy[2*S];
  /*@
  loop invariant i <= S;
  loop invariant 0 <= i;
  */
  for(i=0;i < S;i++) {
    acopy[2*S - (i+1)] = a[2*S - (i+1)];
    acopy[i] = a[i];
  }
  /*@
  loop invariant \forall integer l; 2*S - i <= l < 2*S ==> acopy[l] == a[l];
  loop invariant \forall integer k; 0 <= k < i ==> acopy[k] == a[k];
  loop invariant \forall integer j; 0 <= j < 2*S ==> acopy[j] == a[j];
  loop invariant \forall integer j; (0 <= j < i) || (2*S - i <= j < 2*S) ==> acopy[j] == a[j];
  loop invariant i <= 2*S;
  loop invariant 0 <= i;
  */
  for(i=0;i<2*S;i++){
    // @ assert(acopy[i] == a[i]);
  }
  return 0;
}
