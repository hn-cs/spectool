int sumArray(int *a, int n) {
    int p = 0, sum = 0;

    /*@
    loop invariant n >= 0 ==> p <= n;
    loop invariant n <= 0 ==> p == 0;
    loop invariant n <= 0 ==> sum == 0;
    loop invariant p > 0 ==> n > 0;
    loop invariant p < n ==> 0 <= p < n;
    loop invariant p == n ==> sum == \sum integer k; 0 <= k < n; a[k];
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