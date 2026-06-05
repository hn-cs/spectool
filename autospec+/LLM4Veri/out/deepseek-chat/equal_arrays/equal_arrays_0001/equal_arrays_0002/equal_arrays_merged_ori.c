/*@
requires \valid(b+(0..n-1));
requires \valid(a+(0..n-1));
ensures \result == 1 <==> \forall integer i; 0 <= i < n ==> a[i] == b[i];
ensures \result == 0 <==> \exists integer i; 0 <= i < n && a[i] != b[i];
assigns \nothing;
*/
int check(int *a, int *b, int n) {
    /*@
    loop invariant \forall integer j; 0 <= j < i ==> a[j] == b[j];
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