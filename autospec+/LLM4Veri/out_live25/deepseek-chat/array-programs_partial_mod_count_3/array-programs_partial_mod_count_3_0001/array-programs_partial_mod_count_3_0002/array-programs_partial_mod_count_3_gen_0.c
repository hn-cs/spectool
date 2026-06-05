int N = 1000000;
int main(){
int i,j=0,a[N];
  unsigned int R=3;
  /*@
  loop invariant i <= N;
  loop invariant i <= N/2 + 1 ==> \forall integer k; 0 <= k < i ==> a[k] == k+1;
  loop invariant \forall integer k; 0 <= k < i && k > N/2 ==> a[k] == k%R;
  loop invariant \forall integer k; 0 <= k < i && k <= N/2 ==> a[k] == k+1;
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
  loop invariant 0 <= i <= N;
  loop invariant 0 <= j <= i;
  loop invariant j == \num_of(0, i, \lambda integer k; a[k] == 0);
  loop assigns i, j;
  */
  for(i=0;i<N;i++){
    if (a[i]==0) j++;
     //@assert(j < (N/6)+2);
  }
  return 0;
}
