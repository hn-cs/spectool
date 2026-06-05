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
  loop invariant 0 <= i <= N;
  loop invariant j >= 0;
  loop invariant k <= 0;
  loop invariant j == -k;
  loop invariant \forall integer l; 0 <= l < i ==> a[l] >= k;
  loop assigns i, x, j, k, a[0..N-1];
  loop variant N - i;
  */
  for(i=0;i<N;i++){
    x=unknown();
    if(x) break;
    a[i]=j;
    j=j+i;
    k=k-i;
  }
  for(int l=1;l<i;l++){
    // @ assert(a[l]>=k);
  }
  return 0;
}
