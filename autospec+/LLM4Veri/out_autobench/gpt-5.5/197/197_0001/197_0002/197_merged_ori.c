/*@
requires n >= 0;
requires \valid_read(a + (0 .. n-1));
ensures \result == \sum integer i; 0 <= i < n ==> a[i];
assigns \nothing;
*/
int sumArray(int *a, int n) {
    int p = 0, sum = 0;

    /*@
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