int arraymax(int* a, int n) {
  int i = 1;
  int max = a[0];

  /*@
  loop invariant \forall integer j; 0 <= j < i ==> max >= a[j];
  loop invariant \exists integer j; 0 <= j < i && max == a[j];
  loop invariant 1 <= i;
  loop invariant 0 <= i;
  loop assigns max;
  loop assigns i;
  */
  while (i < n) {
    // Beginning of loop
    if (max < a[i])
    max = a[i];
    i = i + 1;
    // End of loop: Loop invariant comes here
  }
  return max;
}  

// write a test
void main() {
  int arr[5] = {1, 2, 3, 4, 5};
  int sum = arraymax(arr, 5);
  // @ assert sum >= arr[0];
  // @ assert sum >= arr[1];
  // @ assert sum >= arr[2];
  // @ assert sum >= arr[3];
  // @ assert sum >= arr[4];
}