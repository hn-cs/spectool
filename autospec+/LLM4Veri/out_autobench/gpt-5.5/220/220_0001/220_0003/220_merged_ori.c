void reverse(int *a, int n) {
    int i = 0;
    int j = n-1;

    /*@
    loop invariant n > 0 ==> 0 <= j < n;
    loop invariant n <= 0 ==> i == 0;
    loop invariant j < n;
    loop invariant i <= n/2;
    loop invariant i + j == n - 1;
    loop invariant -1 <= j;
    loop invariant j == n - 1 - i;
    loop invariant 0 <= i;
    loop assigns j;
    loop assigns i;
    loop assigns a[0..n-1];
    */
    while (i < n/2) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}

// write a test
void main() {
    int arr[5] = {1, 2, 3, 4, 5};
    reverse(arr, 5);
    // @ assert arr[4] == 1;
}