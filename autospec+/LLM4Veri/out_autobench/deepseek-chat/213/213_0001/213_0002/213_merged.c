// Program to find index of an element in an array
// Behaviors not used in this program

/*@
requires n > 0;
requires \valid(arr + (0..n-1));
ensures \result >= 0 ==> arr[\result] == x;
ensures \result == -1 ==> \forall integer i; 0 <= i < n ==> arr[i] != x;
ensures -1 <= \result < n;
assigns \nothing;
*/
int array_find(int* arr, int n, int x) {
    int i = 0;

    /*@
    loop invariant \forall integer j; 0 <= j < i ==> arr[j] != x;
    loop invariant 0 <= i;
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
    //@ assert index == 2;
}