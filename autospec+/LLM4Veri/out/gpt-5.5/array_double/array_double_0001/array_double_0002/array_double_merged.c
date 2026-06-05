/*@
requires n >= 0;
requires \valid(a + (0..n-1));
requires \forall integer k; 0 <= k < n ==> -1073741824 <= a[k] <= 1073741823;
assigns a[0..n-1];
*/
void arrayDouble(int *a, int n) {
    int p = 0;
    /*@
    loop invariant 0 <= p;
    loop assigns p;
    loop assigns a[0..n-1];
    */
    while (p < n) {
        a[p] = a[p] * 2;
        p = p + 1;
    } 
}
int main() {
    int arr[] = {0,1,2,3,4,5};
    arrayDouble(arr, 6);
    //@ assert \forall integer k; 0 <= k < 6 ==> arr[k] == 2*k;
}