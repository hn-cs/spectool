int binarysearch(int* a, int x, int n) {

    int low = -1;
    int high = n;
    int p;

    /*@
    loop invariant low <= high;
    loop invariant low < high;
    loop invariant low < high || low + 1 <= high;
    loop invariant low < high || 1 <= high - low;
    loop invariant low + 1 <= high;
    loop invariant low + 1 < high;
    loop invariant low + 1 < high;
    loop invariant low + 1 < high;
    loop invariant low + 1 < high;
    loop invariant low + 1 < high;
    loop invariant low + 1 < high;
    loop invariant low + 1 < high;
    loop invariant low + 1 < high;
    loop invariant low + 1 < high;
    loop invariant low + 1 < high;
    loop invariant low + 1 < high;
    loop invariant \forall integer k; high <= k < n ==> a[k] > x;
    loop invariant \forall integer k; 0 <= k <= low ==> a[k] < x;
    loop invariant 1 <= high - low;
    loop invariant 1 <= high - low || low + 1 <= high;
    loop invariant 1 < high - low;
    loop invariant 0 <= high;
    loop invariant 0 <= high || low < high;
    loop invariant 0 <= high || low + 1 <= high;
    loop invariant 0 <= high || 1 <= high - low;
    loop invariant 0 < high;
    loop invariant low == -1 || low < high;
    loop invariant low < high || high <= low + 1;
    loop invariant high == n || low < high;
    loop invariant high <= n;
    loop invariant high <= n && -1 <= low;
    loop invariant -1 <= low;
    loop invariant (low == -1 && high == n) || p == low || p == high;
    loop assigns p;
    loop assigns low;
    loop assigns high;
    */
    while (low+1 < high) {
        p = (low + high) / 2;
        if (a[p] == x) 
            return p;
        else 
            if (a[p] < x)
            low = p;
            else high = p;
    }
    return -1;
}

// write a test
void main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = binarysearch(arr, 3, 5);
    // @ assert arr[sum] == 3;
}