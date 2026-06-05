#include<limits.h>
#include<limits.h>
/*@
assigns \nothing;
ensures 1 < \result < 6;
*/
unsigned int unknown1();
/*@
    requires R!=0;
    ensures 0 < \result < 1000/R;
*/
int unknown2(unsigned int R);
int N = 1000;
int main(){
int i,j=0,k=0,a[N];
unsigned int R=unknown1();
int lim=unknown2(R);
 // @ assert(R>1 && R<6);
// @ assert(0 < lim && lim < N/R);
  /*@
  loop invariant lim < N;
  loop invariant R * lim < N;
  loop invariant lim <= N / R;
  loop invariant 0 < R * lim;
  loop invariant \forall integer t; 0 <= t < i ==> a[t] <= N;
  loop invariant \forall integer t; 0 <= t < i && a[t] != t + 1 ==> t > N / R && a[t] == t % R;
  loop invariant \forall integer t; 0 <= t < i && a[t] == 0 ==> R <= t;
  loop invariant \forall integer t; 0 <= t < i && t <= N / R ==> a[t] > 0;
  loop invariant \forall integer t; 0 <= t < i && t % R == 0 && t <= N / R ==> a[t] == t + 1;
  loop invariant \forall integer t; 0 <= t < i && a[t] == t % R ==> 0 <= a[t] < R;
  loop invariant lim < N / R;
  loop invariant k == \numof(integer t; 0 <= t < i && a[t] == 0);
  loop invariant k <= lim;
  loop invariant k <= i;
  loop invariant j == 0;
  loop invariant j <= i;
  loop invariant i <= N;
  loop invariant \valid(a + (0..N-1));
  loop invariant \forall integer t; 0 <= t < i ==> a[t] == t + 1 || a[t] == t % R;
  loop invariant \forall integer t; 0 <= t < i ==> 0 <= a[t] <= t + 1;
  loop invariant \forall integer t; 0 <= t < i ==> (a[t] == 0 ==> t > N / R && t % R == 0);
  loop invariant \forall integer t; 0 <= t < i ==> (!(t > N / R && t % R == 0) ==> a[t] != 0);
  loop invariant \forall integer t; 0 <= t < i && t <= N / R ==> a[t] == t + 1;
  loop invariant \forall integer t; 0 <= t < i && t % R != 0 ==> a[t] != 0;
  loop invariant R <= 5;
  loop invariant R < 6;
  loop invariant R != 0;
  loop invariant N == 1000;
  loop invariant 2 <= R;
  loop invariant 1 < R;
  loop invariant 0 <= k;
  loop invariant 0 <= j;
  loop invariant 0 <= i;
  loop invariant 0 < lim;
  loop assigns k;
  loop assigns i;
  loop assigns a[0..N-1];
  */
  for(i=0;i<N;i++){
    a[i]=i+1;
    if(i>N/R && k<lim)
       a[i]=i%R;
    if(a[i]==0) k++;
  }
  /*@
  loop invariant lim < N / R;
  loop invariant k == \numof(integer t; 0 <= t < N && a[t] == 0);
  loop invariant k <= lim;
  loop invariant j == \numof(integer t; 0 <= t < i && a[t] == 0);
  loop invariant j <= k;
  loop invariant j <= i;
  loop invariant j <= (N * (R - 1)) / (R * R);
  loop invariant i <= N;
  loop invariant \forall integer t; 0 <= t < N ==> a[t] == t + 1 || a[t] == t % R;
  loop invariant \forall integer t; 0 <= t < N ==> 0 <= a[t] <= t + 1;
  loop invariant \forall integer t; 0 <= t < N && t <= N / R ==> a[t] == t + 1;
  loop invariant \forall integer t; 0 <= t < N && t % R != 0 ==> a[t] != 0;
  loop invariant \forall integer t; 0 <= t < N && a[t] == 0 ==> t > N / R && t % R == 0;
  loop invariant R <= 5;
  loop invariant R < 6;
  loop invariant R != 0;
  loop invariant N == 1000;
  loop invariant 1 < R;
  loop invariant 0 <= k;
  loop invariant 0 <= j;
  loop invariant 0 <= i;
  loop invariant 0 < lim;
  loop assigns j;
  loop assigns i;
  */
  for(i=0;i<N;i++){
    if (a[i]==0) j++;
     // @ assert(j <= ((N*(R-1))/(R*R)));
  }
  return 0;
}
