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
  loop invariant \separated(acopy + (0..2*S-1), a + (0..2*S-1));
  loop invariant \forall integer k; 2*S - i <= k < 2*S ==> acopy[k] == a[k];
  loop invariant \forall integer k; 0 <= k < i ==> acopy[k] == a[k];
  loop invariant S <= 2*S - i;
  loop invariant S <= 2*S - i || 2*S - (i + 1) < 2*S;
  loop invariant S < 2*S - i;
  loop invariant 2*S - (i + 1) <= 2*S;
  loop invariant 2*S - (i + 1) <= 2*S;
  loop invariant 2*S - (i + 1) <= 2*S;
  loop invariant 2*S - (i + 1) <= 2*S;
  loop invariant 2*S - (i + 1) <= 2*S;
  loop invariant 2*S - (i + 1) <= 2*S;
  loop invariant 2*S - (i + 1) <= 2*S;
  loop invariant 2*S - (i + 1) <= 2*S;
  loop invariant 2*S - (i + 1) < 2*S;
  loop invariant 0 <= 2*S - (i + 1);
  loop invariant 0 <= 2*S - (i + 1) || S <= 2*S - i;
  loop invariant 0 <= 2*S - (i + 1) || 2*S - (i + 1) < 2*S;
  loop invariant 0 < 2*S - (i + 1);
  loop invariant i <= S;
  loop invariant i <= 2*S - i;
  loop invariant S < INT_MAX/2;
  loop invariant 1 < S;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns acopy[0..2*S-1];
  */
  for(i=0;i < S;i++) {
    acopy[2*S - (i+1)] = a[2*S - (i+1)];
    acopy[i] = a[i];
  }
  /*@
  loop invariant i <= 2*S;
  loop invariant S <= 2*S;
  loop invariant S < INT_MAX/2;
  loop invariant 2 < 2*S;
  loop invariant 1 < S;
  loop invariant 0 <= i;
  loop assigns i;
  */
  for(i=0;i<2*S;i++){
    // @ assert(acopy[i] == a[i]);
  }
  return 0;
}
