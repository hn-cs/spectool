/*@
requires n > 0;
requires \valid_read(a + (0..n-1));
ensures \exists integer k; 0 <= k < n && \result == a[k];
ensures \forall integer k; 0 <= k < n ==> \result >= a[k];
assigns \nothing;
*/
int arraymax(int* a, int n) {
  int i = 1;
  int max = a[0];
  /*@
  loop invariant i == 1 ==> max == a[0];
  loop invariant i <= n || n <= 0;
  loop invariant a[0] <= max;
  loop invariant \forall integer k; 0 <= k < n ==> a[k] == \at(a[k],LoopEntry);
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
  int sum = arraymax(arr, 5);
  // @ assert sum == 5;
}