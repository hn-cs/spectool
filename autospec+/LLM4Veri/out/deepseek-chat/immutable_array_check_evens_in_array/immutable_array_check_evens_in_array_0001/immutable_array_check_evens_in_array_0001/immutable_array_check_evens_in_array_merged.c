int areElementsEven(int *a, int n) {
    int p = 0;
    /*@
    loop invariant \forall integer i; 0 <= i < p ==> a[i] % 2 == 0;
    loop invariant 0 <= p;
    loop assigns p;
    */
    while (p < n) {
        if (a[p] % 2 != 0) {
            return 0;
        }
        p = p + 1;
    }
    return 1;
}
void main() {
    int arr[] = {2,4,6,8,10};
    int res = areElementsEven(arr, 5);
    // @ assert res == 1;
}