/*@
requires n >= 0;
requires \valid_read(a + (0..n-1));
ensures \result == 1 ==> \exists integer i; 0 <= i < n && a[i] == x;
ensures \result == 0 || \result == 1;
ensures \result == 0 ==> \forall integer i; 0 <= i < n ==> a[i] != x;
assigns \nothing;
*/
int arraySearch(int *a, int x, int n) {
    int p = 0;

    /*@
    loop invariant \forall integer i; 0 <= i < p ==> a[i] != x;
    loop invariant 0 <= p;
    loop assigns p;
    */
    while (p < n) {
        if (a[p] == x) {
            return 1;
        }
        p++;
    }
    return 0;
}

// write a test
void main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = arraySearch(arr, 3, 5);
    //@ assert sum == 1;
}