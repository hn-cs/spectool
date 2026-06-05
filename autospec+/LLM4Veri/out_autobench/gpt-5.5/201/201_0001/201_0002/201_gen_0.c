/*@
requires n >= 0;
requires \valid_read(a + (0..n-1));
requires \valid(sum);
requires \separated(sum, a + (0..n-1));
requires -2147483648 <= x * \numof(integer k; 0 <= k < n && a[k] == x) <= 2147483647;
assigns *sum;
ensures \result == \numof(integer k; 0 <= k < n && a[k] == x);
ensures *sum == \result * x;
*/
int func(int *a, int n, int x, int *sum) {
    int p = 0;
    int count = 0;
    *sum = 0;

    /*@
    loop invariant p <= n;
    loop invariant n - p;
    loop invariant count == \numof(integer k; 0 <= k < p && a[k] == x);
    loop invariant count <= p;
    loop invariant 0 <= p;
    loop invariant 0 <= count;
    loop invariant *sum == count * x;
    loop assigns p;
    loop assigns count;
    loop assigns *sum;
    */
    while (p < n) {
        if (a[p] == x) {
            count = count + 1;
            *sum = *sum + x;
        }
        p = p + 1;
    }
    Label_a:
    *sum += 0;
    // @ assert \at(*sum, Label_a) == count*x;
    return count;
}

// write a test
void main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = 0;
    int count = func(arr, 5, 3, &sum);
    // @ assert sum == count*3;
}