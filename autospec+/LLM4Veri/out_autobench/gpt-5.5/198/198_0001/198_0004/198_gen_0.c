/*@
requires n >= 0;
requires n <= 1073741823;
requires n == 0 || \valid_read(a + (0..n-1));
requires \forall integer i, j; 0 <= i <= j < n ==> a[i] <= a[j];
assigns \nothing;
ensures \result == -1 <==> \forall integer i; 0 <= i < n ==> a[i] != x;
ensures \result != -1 ==> 0 <= \result < n && a[\result] == x;
*/
int binarysearch(int* a, int x, int n) {

    int low = -1;
    int high = n;
    int p;

    /*@
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