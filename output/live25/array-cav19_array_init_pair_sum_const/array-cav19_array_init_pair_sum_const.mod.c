int main()
{
  int i;
  int N=100000;
  int a[N];
  int b[N];
  int c[N];
  //@ admit \separated(a+(0 .. N-1), b+(0 .. N-1), c+(0 .. N-1));
  for(i=0;i<N;i++) {
    a[i]=1;
    b[i]=2;
  }
  for(i=0;i<N;i++){
    c[i]=a[i]+b[i];
  }
  for(i=1;i<N;i++){
    //@ assert(c[i] >= 3);
  }
  return 0;
}
