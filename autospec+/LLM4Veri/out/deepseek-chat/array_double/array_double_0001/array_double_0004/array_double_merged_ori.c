/*@
requires n >= 0;
requires \valid(a+(0..n-1));
ensures \forall integer k; 0 <= k < n ==> a[k] == 2 * \at(a[k], Pre);
*/
void arrayDouble(int *a, int n) {
    int p = 0;
    /*@
    loop invariant p == 0 || \forall integer k; 0 <= k < p ==> a[k] == 2 * \at(a[k], Pre);
    loop invariant \forall integer k; p <= k < n ==> a[k] == \at(a[k], Pre);
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
    // @ assert \forall integer k; 0 <= k < 6 ==> arr[k] == 2*k;
}