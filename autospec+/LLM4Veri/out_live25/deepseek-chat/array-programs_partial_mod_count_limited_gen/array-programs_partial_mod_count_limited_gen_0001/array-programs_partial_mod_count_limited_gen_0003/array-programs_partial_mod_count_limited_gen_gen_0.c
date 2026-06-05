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
  loop invariant i <= N;
  loop invariant k == \numof(0 <= p < i; a[p] == 0);
  loop invariant k <= lim;
  loop invariant k == \numof(0 <= p < i; a[p] == 0);
  loop invariant k <= lim;
  loop invariant i <= N;
  loop invariant \forall integer p; 0 <= p < i ==> a[p] == p+1 || a[p] == p%R;
  loop invariant N - i;
  loop invariant 0 <= k;
  loop invariant 0 <= i;
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
  loop invariant j == \numof(0 <= p < i; a[p] == 0);
  loop invariant j <= ((N*(R-1))/(R*R));
  loop invariant i <= N;
  loop invariant 0 <= j;
  loop invariant 0 <= i;
  loop assigns j;
  loop assigns i;
  */
  for(i=0;i<N;i++){
    if (a[i]==0) j++;
     // @ assert(j <= ((N*(R-1))/(R*R)));
  }
  return 0;
}
