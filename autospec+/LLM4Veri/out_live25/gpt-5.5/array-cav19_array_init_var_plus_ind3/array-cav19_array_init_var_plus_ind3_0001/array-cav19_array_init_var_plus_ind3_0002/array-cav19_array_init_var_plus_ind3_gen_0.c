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
  loop invariant j <= 0;
  loop invariant i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] <= 0;
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
    j=j-i;
  }
  /*@
  loop invariant 4 <= k;
  loop invariant i < 4 ==> k == 4;
  loop invariant i >= 4 ==> k <= i;
  loop invariant \forall integer l; 0 <= l < i ==> a[l] <= 0;
  loop assigns k;
  */
  for(int k=4;k<i;k++){
    // @ assert(a[k] <= 0);
  }
  return 0;
}
