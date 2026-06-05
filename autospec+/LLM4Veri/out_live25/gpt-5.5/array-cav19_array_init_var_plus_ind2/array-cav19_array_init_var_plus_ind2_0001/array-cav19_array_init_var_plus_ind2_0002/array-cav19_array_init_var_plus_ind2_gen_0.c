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
  int k=0;
  int a[N];
  int x=unknown();
  /*@
  loop invariant k <= 0;
  loop invariant j == -k;
  loop invariant i <= N;
  loop invariant \forall integer l; 0 <= l < i ==> a[l] >= k;
  loop invariant 0 <= j;
  loop invariant 0 <= i;
  loop assigns x;
  loop assigns k;
  loop assigns j;
  loop assigns i;
  loop assigns a[0..N-1];
  */
  for(i=0;i<N;i++){
    x=unknown();
    if(x) break;
    a[i]=j;
    j=j+i;
    k=k-i;
  }
  /*@
  loop invariant 0 <= i <= N;
  loop invariant 1 <= l <= i + 1;
  loop invariant \forall integer m; 0 <= m < i ==> a[m] >= k;
  loop assigns l;
  loop variant i - l;
  */
  for(int l=1;l<i;l++){
    // @ assert(a[l]>=k);
  }
  return 0;
}
