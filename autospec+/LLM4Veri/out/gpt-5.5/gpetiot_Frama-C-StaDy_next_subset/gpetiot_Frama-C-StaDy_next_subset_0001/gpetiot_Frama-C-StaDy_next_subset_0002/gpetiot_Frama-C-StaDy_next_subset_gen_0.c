/*@ 
predicate is_dset{L}(int *a, integer n) =
  \forall integer i; 0 <= i < n ==> (a[i] == 0 || a[i] == 1);
predicate is_eq{L1,L2}(int *a, integer n) =
  \forall integer i; 0 <= i < n ==> \at(a[i],L1) == \at(a[i],L2);
predicate lt{L1,L2}(int* a, integer i) =
  \at(a[i],L1) < \at(a[i],L2); 
*/
int nextSubset(int s[], int n) {
  int i,k;
  /*@
  loop invariant k < n;
  loop invariant \forall integer j; k < j < n ==> s[j] != 0;
  loop assigns k;
  */
  for (k = n-1; k >= 0; k--) { if (s[k] == 0) { break; } }
  if (k == -1) { return -1; }
  s[k] = 1;
  /*@
  loop invariant k + 1 <= i <= n;
  loop invariant is_dset(s, n);
  loop invariant s[k] == 1;
  loop invariant \forall integer j; k < j < i ==> s[j] == 0;
  loop assigns i, s[k+1..n-1];
  loop variant n - i;
  */
  for (i = k+1; i < n; i++) { s[i] = 0; }
  // @ assert is_dset(s,n);
  return k;
}