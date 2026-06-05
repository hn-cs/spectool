/*@
requires n >= 0;
ensures \result == n/2 * (n/2 + 1);
assigns \nothing;
*/
int func(int n) {
    int sum = 0;
    int i = 0;

    /*@
    loop invariant sum == i * (i - 1);
    loop invariant i <= n/2 + 1;
    loop invariant \exists integer k; 0 <= k <= i && sum == 2 * (0+1+...+k-1);
    loop invariant 0 <= i;
    loop assigns sum;
    loop assigns i;
    */
    while(i <= n/2) {
        sum = sum + 2*(i);
        i++;
    }
    return sum;
}

// write a test
void main() {
    int t = func(10);
    //@ assert t == 30;
}