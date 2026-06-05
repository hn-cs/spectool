int arraysearch(int* a, int x, int n) { 
  /*@
  loop invariant 0 <= p <= n;
  loop invariant \forall integer k; 0 <= k < p ==> a[k] != x;
  loop assigns p;
  loop variant n - p;
  */
  for (int p = 0; p < n; p++) {
    if (x == a[p]) 
       return 1;
  }
  return 0;
}
void main() {
  int arr[5] = {1, 2, 3, 4, 5};
  int sum = arraysearch(arr, 3, 5);
  // @ assert sum == 1;
}