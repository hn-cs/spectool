int main()
{
  int i;
  int N=100000;
  int a[N];
  int b[N];
  int c[N];
  /*@
  loop invariant i <= N;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns b[0..N-1];
  loop assigns a[0..N-1];
  */
  for(i=0;i<N;i++) {
    a[i]=1;
    b[i]=2;
  }
  /*@
  loop invariant i <= N;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns c[0..N-1];
  */
  for(i=0;i<N;i++){
    c[i]=a[i]+b[i];
  }
  /*@
  loop invariant 1 <= i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> c[k] == 3;
  loop assigns i;
  */
  for(i=1;i<N;i++){
    // @ assert(c[i] >= 3);
  }
  return 0;
}
