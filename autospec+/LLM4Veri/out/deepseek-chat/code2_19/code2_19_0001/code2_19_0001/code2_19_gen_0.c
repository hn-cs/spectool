/*@
requires n > 0;
*/
void foo(int n)
{
    int x = 0;
    int m = 0;
    /*@
    loop invariant 0 <= x <= n;
    loop invariant 0 <= m < n;
    loop invariant m <= x;
    loop invariant m == x ==> \at(m, Pre) == x;
    loop assigns x, m;
    */
    while (x < n) {
        if (unknown()) {
            m = x;
        }
        x = x + 1;
    }
    if(n > 0) {
       // @ assert m < n;
       // @ assert m >= 0;
    }
}