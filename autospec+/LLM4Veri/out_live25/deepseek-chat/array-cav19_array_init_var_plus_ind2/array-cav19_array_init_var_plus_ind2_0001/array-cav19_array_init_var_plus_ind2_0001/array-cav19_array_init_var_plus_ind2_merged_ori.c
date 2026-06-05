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
  loop invariant k == -\sum_{t=0}^{i-1} t;
  loop invariant j == k;
  loop invariant j == \sum_{t=0}^{i-1} t;
  loop invariant j + k == 0;
  loop invariant i <= N;
  loop invariant \forall integer p; 0 <= p < i ==> a[p] == \sum_{t=0}^{p-1} t;
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
  for(int l=1;l<i;l++){
    // @ assert(a[l]>=k);
  }
  return 0;
}
