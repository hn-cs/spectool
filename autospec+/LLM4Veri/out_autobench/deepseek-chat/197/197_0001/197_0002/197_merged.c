/*@
requires n >= 0;
requires \valid(a + (0..n-1));
ensures \result == \sum(0, n-1, a[\at(\lambda integer i; a[i], Pre)]);
assigns \nothing;
*/
int sumArray(int *a, int n) {
    int p = 0, sum = 0;

    /*@
    loop invariant sum == \sum (0..p-1) a[j];
    loop invariant p <= n;
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
    //@ assert sum == 15;
}