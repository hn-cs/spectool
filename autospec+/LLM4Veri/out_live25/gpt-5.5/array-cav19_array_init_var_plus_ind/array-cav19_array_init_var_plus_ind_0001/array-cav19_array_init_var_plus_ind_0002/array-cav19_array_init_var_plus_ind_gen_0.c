#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
int N = 100000;
int main()
{
  int i;
  int j=0;
  int a[N];
  int x=unknown();
  /*@
  loop invariant i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] >= 0;
  loop invariant 0 <= j;
  loop invariant 0 <= i;
  loop assigns x;
  loop assigns j;
  loop assigns i;
  loop assigns a[0..N-1];
  */
  for(i=0;i<N;i++){
    x=unknown();
    if(x) break;
    a[i]=j;
    j=j+i;
  }
  /*@
  loop invariant 1 <= k <= i;
  loop invariant \forall integer t; 0 <= t < i ==> a[t] >= 0;
  loop assigns k;
  */
  for(int k=1;k<i;k++){
    // @ assert(a[k]>=0);
  }
  return 0;
}
