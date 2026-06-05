/*@
requires n >= 0;
requires \valid_read(b + (0..n-1));
requires \valid_read(a + (0..n-1));
ensures \result == 1 <==> \forall integer i; 0 <= i < n ==> a[i] == b[i];
ensures \result == 0 <==> \exists integer i; 0 <= i < n && a[i] != b[i];
assigns \nothing;
*/
int check(int *a, int *b, int n) {
    /*@
    loop invariant \forall integer k; 0 <= k < i ==> a[k] == b[k];
    loop invariant 0 <= i;
    loop assigns i;
    */
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int a[] = {1,2,3,4,5};
    int b[] = {1,2,3,4,5};
    int ans = check(a, b, 5);
    // @ assert ans == 1;
}