#include<limits.h>
/*@
   requires R!=0;
   ensures 0 < \result < 1000000/R;
*/ 
int unknown(unsigned int R);
int N = 1000000;
int main(){
int i,j=0,k=0,a[N];
unsigned int R=1;
int lim=unknown(R);
// @ assert(0 < lim && lim < N/R);
  /*@
  loop invariant k <= lim;
  loop invariant k <= i;
  loop invariant i <= N;
  loop invariant \forall integer t; 0 <= t < i && a[t] == 0 ==> t % R == 0;
  loop invariant 0 <= k;
  loop invariant 0 <= i;
  loop assigns k;
  loop assigns i;
  loop assigns a[0..N-1];
  */
  for(i=0;i<N;i++){
    a[i]=i+1;
    if(k<lim)
       a[i]=i%R;
    if(a[i]==0) k++;
  }
  /*@
  loop invariant 0 <= i <= N;
  loop invariant j == \numof(\integer t; 0 <= t < i; a[t] == 0);
  loop invariant j <= k;
  loop invariant j < N/R;
  loop assigns i, j;
  */
  for(i=0;i<N;i++){
    if (a[i]==0) j++;
     // @ assert(j < N/R);
  }
  return 0;
} 
