#include<limits.h>
/*@
assigns \nothing;
ensures 1 < \result < INT_MAX;
*/
int unknown();
int main()
{
  int S=unknown();
  // @ assert(S>1);
  long long i;
  long long a[S];
  /*@
  loop invariant i <= S;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] == (k-1)*(k+1);
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns a[0..S-1];
  */
  for(i=0;i<S;i++)
    a[i]=((i-1)*(i+1));
  /*@
  loop invariant i <= S;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns a[0..S-1];
  */
  for(i=0;i<S;i++)
    a[i]=a[i]-(i*i);
  for(i=0;i<S;i++){
    // @ assert(a[i]==-1);
  }
  return 0;
}
