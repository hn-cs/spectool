#include<limits.h>
/*@
   requires R!=0;
   ensures 0 < \result < 1000000/R;
*/ 
int unknown(unsigned int R);
int N = 1000000;
int main(){
int i,j=0,k=0,a[N];
unsigned int R=3;
int lim=unknown(R);
// @ assert(0 < lim && lim < N/R);
  /*@
  loop invariant 0 <= i <= N;
  loop invariant \forall integer t; 0 <= t < i && t <= N/2 ==> a[t] == t+1;
  loop invariant \forall integer t; N/2 < t < i && k < lim ==> a[t] == t%R;
  loop invariant \forall integer t; N/2 < t < i && !(k < lim) ==> a[t] == t+1;
  loop invariant 0 <= k <= lim;
  loop invariant k == \num_of(0, i-1, \lambda integer t; a[t] == 0);
  loop assigns i, k, a[0..N-1];
  */
  for(i=0;i<N;i++){
    a[i]=i+1;
    if(i>N/2 && k<lim)
       a[i]=i%R;
    if(a[i]==0) k++;
  }
  for(i=0;i<N;i++){
    if (a[i]==0) j++;
     // @ assert(j < (N/(2*R))+2);
  }
  return 0;
}
