/*@
requires n <= 0 || \valid_read(a + (0..n-1));
ensures n > 0 ==> \result == \sum integer k; 0 <= k < n; a[k];
ensures n <= 0 ==> \result == 0;
assigns \nothing;
*/
int sumArray(int *a, int n) {
    int p = 0, sum = 0;

    /*@
    loop invariant sum == \sum integer k; 0 <= k < p; a[k];
    loop invariant p == 0 ==> sum == 0;
    loop invariant p <= n || n < 0;
    loop invariant 0 <= p;
    loop assigns sum;
    loop assigns p;
    */
    while (p < n) {
        sum = sum + a[p];
        p++;
    }
    return sum;
}

// write a test
void main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = sumArray(arr, 5);
    // @ assert sum == 15;
}