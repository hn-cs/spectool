/*@
  assigns \nothing;
  ensures -100000 < \result < 100000;
*/
int unknown();
int N = 100000;
int main()
{
  int i;
  int a[N];
  int b[N];
  int c[N];
  int x= unknown();
  /*@
  loop invariant x < 100000;
  loop invariant i <= N;
  loop invariant \forall integer j; 0 <= j < i ==> -100000 < b[j] < 100000;
  loop invariant \forall integer j; 0 <= j < i ==> -100000 < a[j] < 100000;
  loop invariant 0 <= i;
  loop invariant -100000 < x;
  loop assigns x;
  loop assigns i;
  loop assigns b[0..N-1];
  loop assigns a[0..N-1];
  */
  for(i=0;i<N;i++) {
    x = unknown();
    // @ assert (x > -100000 && x < 100000);
    a[i]=x;
    b[i]=-x;
  }
  /*@
  loop invariant i <= N;
  loop invariant \forall integer j; 0 <= j < i ==> c[j] == 0;
  loop invariant \forall integer j; 0 <= j < N ==> b[j] == -a[j];
  loop invariant \forall integer j; 0 <= j < N ==> -100000 < b[j] < 100000;
  loop invariant \forall integer j; 0 <= j < N ==> -100000 < a[j] < 100000;
  loop invariant 0 <= i;
  loop assigns i;
  loop assigns c[0..N-1];
  */
  for(i=0;i<N;i++){
    c[i]=a[i]+b[i];
  }
  for(i=1;i<N;i++){
    // @ assert(c[i] == 0);
  }
  return 0;
}
