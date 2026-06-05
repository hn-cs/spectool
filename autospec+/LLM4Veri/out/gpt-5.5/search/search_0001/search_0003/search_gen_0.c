int arraysearch(int* a, int x, int n) { 
  for (int p = 0; p < n; p++) {
    if (x == a[p]) 
    // @ assert \exists integer k;  0 <= k <= p && x == a[k];
       return 1;
  }
  /*@
  loop invariant 0 <= p <= n;
  loop invariant \forall integer k; 0 <= k < p ==> x != a[k];
  loop assigns p;
  loop variant n - p;
  */
  return 0;
} 