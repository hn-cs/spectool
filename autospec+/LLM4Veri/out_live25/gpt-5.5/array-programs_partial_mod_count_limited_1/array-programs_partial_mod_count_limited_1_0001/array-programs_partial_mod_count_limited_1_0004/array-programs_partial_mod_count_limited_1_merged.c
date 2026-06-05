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
//@ assert(0 < lim && lim < N/R);
  /*@
  loop invariant lim < N / R;
  loop invariant k == lim ==> lim <= i;
  loop invariant k == i || k == lim;
  loop invariant k <= lim;
  loop invariant k <= i;
  loop invariant k < lim ==> k == i;
  loop invariant i <= N;
  loop invariant i < lim ==> k == i;
  loop invariant \forall integer t; 0 <= t < i ==> 0 <= a[t] <= t + 1;
  loop invariant \forall integer t; 0 <= t < i && t < lim ==> a[t] == 0;
  loop invariant \forall integer t; 0 <= t < i && lim <= t ==> a[t] == t + 1;
  loop invariant \forall integer t; 0 <= t < i && a[t] == 0 ==> t % R == 0;
  loop invariant R == 1;
  loop invariant 0 <= k;
  loop invariant 0 <= i;
  loop invariant 0 < lim;
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
  loop invariant lim <= i ==> j == lim;
  loop invariant j == lim ==> lim <= i;
  loop invariant j == i || j == lim;
  loop invariant j <= lim;
  loop invariant j < lim ==> j == i;
  loop invariant j < i ==> j == lim;
  loop invariant i < lim ==> j == i;
  loop invariant \forall integer t; 0 <= t < i ==> (a[t] == 0 <==> t < lim);
  loop invariant \forall integer t; 0 <= t < N && t < lim ==> a[t] == 0;
  loop invariant \forall integer t; 0 <= t < N && lim <= t ==> a[t] == t + 1;
  loop invariant lim < N / R;
  loop invariant j <= i;
  loop invariant i <= N;
  loop invariant R == 1;
  loop invariant 0 <= j;
  loop invariant 0 <= i;
  loop invariant 0 < lim;
  loop assigns j;
  loop assigns i;
  */
  for(i=0;i<N;i++){
    if (a[i]==0) j++;
     //@ assert(j < N/R);
  }
  return 0;
} 
