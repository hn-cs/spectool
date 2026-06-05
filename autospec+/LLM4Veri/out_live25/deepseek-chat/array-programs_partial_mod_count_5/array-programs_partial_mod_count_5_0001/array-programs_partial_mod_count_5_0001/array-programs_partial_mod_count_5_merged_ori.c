int N = 1000000;
int main(){
int i,j=0,a[N];
  unsigned int R=5;
  /*@
  loop invariant i <= N;
  loop invariant \forall integer k; N/2 < k < i ==> a[k] == k % R;
  loop invariant \forall integer k; 0 <= k < i <= N/2 ==> a[k] == k+1;
  loop invariant N - i;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns a[0..N-1];
  */
  for(i=0;i<N;i++){
    a[i]=i+1;
    if(i>N/2)
       a[i]=i%R;
  }
  for(i=0;i<N;i++){
    if (a[i]==0) j++;
     //@assert(j < (N/10));
  }
  return 0;
}
