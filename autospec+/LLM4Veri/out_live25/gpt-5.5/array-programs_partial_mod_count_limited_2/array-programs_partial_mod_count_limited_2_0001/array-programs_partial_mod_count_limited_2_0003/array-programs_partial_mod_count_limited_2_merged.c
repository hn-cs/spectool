#include<limits.h>
/*@
   requires R!=0;
   ensures 0 < \result < 1000000/R;
*/ 
int unknown(unsigned int R);
int N = 1000000;
int main(){
int i,j=0,k=0,a[N];
unsigned int R=2;
int lim=unknown(R);
// @ assert(0 < lim && lim < N/R);
  /*@
  loop invariant k <= i;
  loop invariant k < N / R;
  loop invariant j == 0;
  loop invariant \forall integer t; 0 <= t < i ==> 0 <= a[t] <= t + 1;
  loop invariant \forall integer t; 0 <= t < i ==> (a[t] == t + 1 || a[t] == t % R);
  loop invariant \forall integer t; 0 <= t < i && t <= N / 2 ==> a[t] == t + 1;
  loop invariant N == 1000000;
  loop invariant k == \numof(integer t; 0 <= t < i && a[t] == 0);
  loop invariant k <= lim;
  loop invariant k < N / (2 * R);
  loop invariant i <= N;
  loop invariant \forall integer t; 0 <= t < i ==> (a[t] == 0 ==> t > N / 2 && t % R == 0);
  loop invariant R == 2;
  loop invariant N - i;
  loop invariant 0 <= k;
  loop invariant 0 <= i;
  loop invariant 0 < lim && lim < N / R;
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
  loop invariant k == \numof(integer t; 0 <= t < N && a[t] == 0);
  loop invariant k < N / (2 * R);
  loop invariant j == \numof(integer t; 0 <= t < i && a[t] == 0);
  loop invariant j <= k;
  loop invariant i <= N;
  loop invariant \forall integer t; 0 <= t < N ==> (a[t] == 0 ==> t > N / 2 && t % R == 0);
  loop invariant R == 2;
  loop invariant N == 1000000;
  loop invariant N - i;
  loop invariant 0 <= j;
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
