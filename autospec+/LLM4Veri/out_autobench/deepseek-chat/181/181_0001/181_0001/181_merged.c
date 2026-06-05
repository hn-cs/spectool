int arraymax(int* a, int n) {
  int i = 1;
  int max = a[0];

  /*@
  loop invariant \forall integer k; 0 <= k < i ==> max >= a[k];
  loop invariant \exists integer k; 0 <= k < i && max == a[k];
  loop invariant 1 <= i;
  loop assigns max;
  loop assigns i;
  */
  while (i < n) {
    if (max < a[i])
    max = a[i];
    i = i + 1;
  }
  return max;
}

void main() {
  int arr[5] = {1, 2, 3, 4, 5};
  int max = arraymax(arr, 5);
  // @ assert max >= arr[0];
  // @ assert max >= arr[1];
  // @ assert max >= arr[2];
  // @ assert max >= arr[3];
  // @ assert max >= arr[4];
}