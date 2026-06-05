int arraysearch(int* a, int x, int n) { 
  for (int p = 0; p < n; p++) {
    if (x == a[p]) 
    // @ assert \exists integer k;  0 <= k <= p && x == a[k];
       return 1;
  }
  /*@
  loop invariant p >= 0 && (n < 0 || p <= n);
  loop invariant n <= 0 ==> p == 0;
  loop invariant \forall integer k; 0 <= k < p ==> x - a[k] != 0;
  loop invariant \forall integer k; 0 <= k < p ==> a[k] < x || a[k] > x;
  loop invariant \forall integer k; 0 <= k < p && k < n ==> a[k] != x;
  loop invariant p == 0 || p <= n;
  loop invariant p <= n;
  loop invariant p <= n || 0 <= p;
  loop invariant p < n;
  loop invariant n >= 0 ==> p <= n;
  loop invariant n < 0 ==> p == 0;
  loop invariant n - p;
  loop invariant \forall integer k; 0 <= k < p ==> x != a[k];
  loop invariant \forall integer k; 0 <= k < p ==> a[k] != x;
  loop invariant \forall integer k; 0 <= k < p ==> !(x == a[k]);
  loop invariant \forall integer k; 0 <= k < n && a[k] == x ==> p <= k;
  loop invariant 0 <= p;
  loop invariant 0 < p;
  */
  return 0;
} 