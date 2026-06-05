int N = 100000;
int main()
{
  int a[N];
  int b[N];
  int i;
  int sum=0;
  /*@
  loop invariant i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] == k;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns a[0..N-1];
  */
  for (i=0;i<N;i++) {
    a[i] = i;
  }
  /*@
  loop invariant i <= N;
  loop invariant \forall integer k; N - i <= k < N ==> b[k] == N - k - 1;
  loop invariant \forall integer k; 0 <= k < i ==> b[N - k - 1] == k;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns b[0..N-1];
  */
  for (i=0;i<N;i++) {
    b[N-i-1]=i;
  }
  for (i=0;i<N;i++) {
    sum=sum+(a[i]-b[N-i-1]);
  }
  //@assert(sum == 0);
  return 0;
}
