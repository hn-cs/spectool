int N = 100000;
int main()
{
  int a[N];
  int b[N];
  int i;
  int sum=0;
  /*@
  loop invariant i <= N;
  loop invariant \forall integer j; 0 <= j < i ==> a[j] == j;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns a[0..N-1];
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
  return 0;
}
