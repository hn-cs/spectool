// Program to find if the array consists of even elements only

/*@
requires \valid(a+(0..n-1));
ensures n <= 0 ==> \result == 1;
ensures n > 0 ==> (\result == 1 <==> \forall integer i; 0 <= i < n ==> a[i] % 2 == 0);
ensures n > 0 ==> (\result == 0 <==> \exists integer i; 0 <= i < n && a[i] % 2 != 0);
assigns \nothing;
*/
int areElementsEven(int *a, int n) {
    int p = 0;

    /*@
    loop invariant \forall integer k; 0 <= k < p ==> a[k] % 2 == 0;
    loop invariant 0 <= p;
    loop assigns p;
    */
    while (p < n) {
        if (a[p]%2 != 0) {
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
