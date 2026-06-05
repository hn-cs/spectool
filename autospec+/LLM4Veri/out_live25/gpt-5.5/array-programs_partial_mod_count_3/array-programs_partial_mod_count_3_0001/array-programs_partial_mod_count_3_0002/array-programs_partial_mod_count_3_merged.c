int N = 1000000;
int main(){
int i,j=0,a[N];
  unsigned int R=3;
  /*@
  loop invariant j == 0;
  loop invariant i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> (k > N/2 ==> a[k] == k % R);
  loop invariant \forall integer k; 0 <= k < i ==> (k <= N/2 ==> a[k] == k + 1);
  loop invariant R == 3;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns a[0..N-1];
  */
  for(i=0;i<N;i++){
    a[i]=i+1;
    if(i>N/2)
       a[i]=i%R;
  }
  /*@
  loop invariant j == \numof(integer k; 0 <= k < i && a[k] == 0);
  loop invariant j <= i;
  loop invariant j < (N/6) + 2;
  loop invariant i <= N;
  loop invariant \forall integer k; 0 <= k < N ==> (k > N/2 ==> a[k] == k % R);
  loop invariant \forall integer k; 0 <= k < N ==> (k <= N/2 ==> a[k] == k + 1);
  loop invariant R == 3;
  loop invariant 0 <= j;
  loop invariant 0 <= i;
  loop assigns j;
  loop assigns i;
  */
  for(i=0;i<N;i++){
    if (a[i]==0) j++;
     //@assert(j < (N/6)+2);
  }
  return 0;
}
