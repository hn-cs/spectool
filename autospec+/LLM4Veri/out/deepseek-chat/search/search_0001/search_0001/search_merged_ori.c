int arraysearch(int* a, int x, int n) { 
  /*@
  loop invariant p <= n;
  loop invariant \forall integer q; 0 <= q < p ==> a[q] != x;
  loop invariant 0 <= p;
  loop assigns p;
  */
  for (int p = 0; p < n; p++) {
    if (x == a[p]) 
    // @ assert \exists integer k;  0 <= k <= p && x == a[k];
       return 1;
  }
  return 0;
} 