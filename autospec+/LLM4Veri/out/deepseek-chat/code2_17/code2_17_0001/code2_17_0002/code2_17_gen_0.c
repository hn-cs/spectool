/*@
requires n > 1;
*/
void foo(int n)
{
    int x = 1;
    int m = 1;
    /*@
    loop invariant m <= x;
    loop invariant m >= 1;
    loop invariant x - m <= 1;
    loop invariant m == 1 || m == x - 1;
    loop invariant \exists integer k; 1 <= k <= x && m == k;
    loop invariant x <= n;
    loop invariant m <= n;
    loop invariant 1 <= x;
    loop invariant 1 <= m;
    loop assigns x;
    loop assigns m;
    */
    while (x < n) {
        if (unknown()) {
            m = x;
        }
        x = x + 1;
    }
    if(n > 1) {
       // @ assert m < n;
       // @ assert m >= 1;
    }
}