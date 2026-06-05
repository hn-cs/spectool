#include<limits.h>
/*@
   requires R!=0;
   ensures 0 < \result < 1000000/R;
*/ 
int unknown(unsigned int R);
int N = 1000000;
int main(){
int i,j=0,k=0,a[N];
unsigned int R=5;
int lim=unknown(R);
// @ assert(0 < lim && lim < N/R);
  /*@
  loop invariant k <= i;
  loop invariant i <= N;
  loop invariant \forall integer l; 0 <= l < i && l <= N/2 ==> a[l] == l+1;
  loop invariant \forall integer l; 0 <= l < i && a[l] == 0 ==> (l > N/2 && k <= lim);
  loop invariant 0 <= k;
  loop invariant 0 <= i;
  loop assigns k;
  loop assigns i;
  loop assigns a[0..N-1];
  */
  for(i=0;i<N;i++){
    a[i]=i+1;
    if(i>N/2 && k<lim)
       a[i]=i%R;
    if(a[i]==0) k++;
  }
  /*@
  loop invariant j == k;
  loop invariant j <= lim;
  loop invariant i <= N;
  loop invariant \forall integer l; 0 <= l < i ==> (a[l] == 0) ==> (l > N/2 && k <= lim);
  loop invariant \forall integer l; 0 <= l < i && a[l] == 0 ==> j <= lim;
  loop invariant 0 <= i;
  loop assigns j;
  loop assigns i;
  */
  for(i=0;i<N;i++){
    if (a[i]==0) j++;
     // @ assert(j < N/(2*R));
  }
  return 0;
}
