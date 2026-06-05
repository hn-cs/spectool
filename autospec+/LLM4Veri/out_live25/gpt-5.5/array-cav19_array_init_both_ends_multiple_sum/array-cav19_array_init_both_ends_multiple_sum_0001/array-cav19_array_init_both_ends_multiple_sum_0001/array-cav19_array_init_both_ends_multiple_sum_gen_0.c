int N = 100000;
int main()
{
  int a[N];
  int b[N];
  int i;
  int sum=0;
  /*@
  loop invariant 0 <= i <= N;
  loop invariant \forall integer k; 0 <= k < i ==> a[k] == k;
  loop assigns i, a[0..N-1];
  loop variant N - i;
  */
  for (i=0;i<N;i++) {
    a[i] = i;
  }
  for (i=0;i<N;i++) {
    b[N-i-1]=i;
  }
  for (i=0;i<N;i++) {
    sum=sum+(a[i]-b[N-i-1]);
  }
  //@assert(sum == 0);
  return 0;
}
