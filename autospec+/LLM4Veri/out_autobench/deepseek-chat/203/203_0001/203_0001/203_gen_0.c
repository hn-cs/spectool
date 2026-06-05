int arraysearch(int* a, int x, int n) { 

  /*@
  loop invariant 0 <= p <= n;
  loop invariant \forall integer i; 0 <= i < p ==> a[i] != x;
  loop assigns p;
  */
  for (int p = 0; p < n; p++) {
    // STart
    if (x == a[p]) 
       return 1;
    // End
  }
  return 0;
}

// write a test
void main() {
  int arr[5] = {1, 2, 3, 4, 5};
  int sum = arraysearch(arr, 3, 5);
  // @ assert sum == 1;
}