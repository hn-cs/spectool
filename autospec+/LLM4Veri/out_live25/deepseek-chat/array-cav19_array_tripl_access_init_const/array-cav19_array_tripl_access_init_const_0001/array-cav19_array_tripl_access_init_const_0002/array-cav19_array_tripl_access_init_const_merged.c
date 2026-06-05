int main()
{
  int i;
  int N=100000;
  int a[3*N+1];
  /*@
  loop invariant i <= N+1;
  loop invariant \forall integer k; 0 <= k < i ==> a[3*k] == 0 && a[3*k+1] == 0 && a[3*k+2] == 0;
  loop invariant 0 <= i;
  */
  for(i=0; i<= N; i++) {
    a[3*i] =0;
    a[3*i+1]=0;
    a[3*i+2]=0;
  }
  /*@
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns a[0..3*N];
  */
  for(i=0;i<=3*N;i++){
    //@ assert(a[i] >= 0);
  }
  return 0;
}
