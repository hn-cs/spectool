int binarysearch(int* a, int x, int n) {

    int low = -1;
    int high = n;
    int p;

    /*@
    loop invariant low < high;
    loop invariant low + 1 <= high;
    loop invariant high <= n;
    loop invariant high - low;
    loop invariant \forall integer i; high <= i < n ==> a[i] > x;
    loop invariant \forall integer i; 0 <= i <= low ==> a[i] < x;
    loop invariant -1 <= low;
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