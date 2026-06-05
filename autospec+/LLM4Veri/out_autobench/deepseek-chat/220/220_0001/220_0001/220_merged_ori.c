void reverse(int *a, int n) {
    int i = 0;
    int j = n-1;

    /*@
    loop invariant n/2 - i;
    loop invariant j < n;
    loop invariant i <= n/2;
    loop invariant i + j == n - 1;
    loop invariant \forall integer k; j < k < n ==> a[k] == \at(a[n-1-k], Pre);
    loop invariant \forall integer k; i <= k <= j ==> a[k] == \at(a[k], Pre);
    loop invariant \forall integer k; 0 <= k < i ==> a[k] == \at(a[n-1-k], Pre);
    loop invariant 0 <= j;
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