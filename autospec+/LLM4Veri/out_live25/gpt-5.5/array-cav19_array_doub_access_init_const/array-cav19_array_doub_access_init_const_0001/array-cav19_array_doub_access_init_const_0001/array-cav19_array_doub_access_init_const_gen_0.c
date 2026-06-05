int main()
{
  int i;
  int N=100000;
  int a[2*N+2];
  /*@
  loop invariant 0 <= i <= N + 1;
  loop invariant \forall integer k; 0 <= k < 2*i ==> a[k] == 0;
  loop assigns i, a[0..2*N+1];
  loop variant N + 1 - i;
  */
  for(i=0;i<=N;i++) {
    a[2*i]=0;
    a[2*i+1]=0;
  }
  for(i=0;i<=2*N;i++){
    // @ assert(a[i]>=0);
  }
  return 0;
}
