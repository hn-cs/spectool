int array_max_advanced(int* arr, int n) {
    int max = arr[0];
    /*@
    loop invariant 0 <= i <= n;
    loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= max;
    loop invariant \exists integer j; 0 <= j < i && max == arr[j];
    loop assigns i, max;
    loop variant n - i;
    */
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    // @ assert \forall integer j; 0 <= j < n ==> arr[j] <= max;
    return max;
}