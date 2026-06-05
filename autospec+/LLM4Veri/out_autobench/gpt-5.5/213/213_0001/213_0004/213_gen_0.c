// Program to find index of an element in an array
// Behaviors not used in this program

/*@
requires n >= 0;
requires \valid_read(arr + (0..n-1));
assigns \nothing;
ensures \result == -1 ==> \forall integer k; 0 <= k < n ==> arr[k] != x;
ensures 0 <= \result < n ==> arr[\result] == x;
ensures 0 <= \result < n ==> \forall integer k; 0 <= k < \result ==> arr[k] != x;
*/
int array_find(int* arr, int n, int x) {
    int i = 0;

    /*@
    loop invariant n <= 0 ==> i == 0;
    loop invariant i == 0 || arr[i-1] != x;
    loop invariant i <= n || n < 0;
    loop invariant \forall integer k; 0 <= k < i ==> arr[k] < x || arr[k] > x;
    loop invariant \forall integer k; 0 <= k < i ==> arr[k] != x;
    loop invariant 0 <= i;
    loop invariant 0 < i ==> 0 < n;
    loop assigns i;
    */
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// write a test
void main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int index = array_find(arr, 5, 3);
    // @ assert index == 2;
}