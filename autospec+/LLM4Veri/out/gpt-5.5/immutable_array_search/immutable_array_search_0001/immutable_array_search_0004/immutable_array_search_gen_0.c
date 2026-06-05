/*@
requires n >= 0 ==> \valid_read(a + (0..n-1));
assigns \nothing;
ensures \result == 0 || \result == 1;
ensures \result == 1 ==> \exists integer i; 0 <= i < n && a[i] == x;
ensures \result == 0 ==> \forall integer i; 0 <= i < n ==> a[i] != x;
*/
int arraysearch(int* a, int x, int n) { 
  /*@
  loop invariant p == 0 || a[p-1] != x;
  loop invariant p <= n || n < 0;
  loop invariant n < 0 ==> p == 0;
  loop invariant \forall integer i; 0 <= i < p ==> a[i] != x;
  loop invariant 0 <= p;
  loop assigns p;
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