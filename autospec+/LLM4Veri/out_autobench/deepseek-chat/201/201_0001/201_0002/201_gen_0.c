/*@
requires \valid(a + (0..n-1));
requires \valid(sum);
requires n >= 0;
ensures \result == \numof(0 <= k < n; a[k] == x);
ensures *sum == \result * x;
assigns *sum;
*/
int func(int *a, int n, int x, int *sum) {
    int p = 0;
    int count = 0;
    *sum = 0;

    /*@
    loop invariant p <= n;
    loop invariant count == \numof(0 <= k < p; a[k] == x);
    loop invariant 0 <= p;
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