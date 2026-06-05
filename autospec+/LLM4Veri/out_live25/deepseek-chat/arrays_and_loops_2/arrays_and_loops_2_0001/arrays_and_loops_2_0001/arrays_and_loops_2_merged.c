int arraymax(int* a, int n) {
  int i = 1;
  int max = a[0];
  /*@
  loop invariant i <= n;
  loop invariant \forall integer k; 0 <= k < i ==> max >= a[k];
  loop invariant \exists integer k; 0 <= k < i && max == a[k];
  loop invariant 0 <= i;
  loop assigns max;
  loop assigns i;
  */
  while (i < n) {
    if (max < a[i])
    max = a[i];
    i = i + 1;
  }
  // @ assert \forall integer k;  0 <= k < n ==> max >=  a[k];
  return max;
}  