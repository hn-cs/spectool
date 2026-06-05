/*@
requires n > 1;
*/
void foo(int n)
{
    int x = 1;
    int m = 1;

    /*@
    loop invariant 0 <= x <= n;
    loop invariant 1 <= m <= n;
    loop invariant m < x;
    loop invariant m >= 1;
    loop invariant m < n;
    loop assigns x, m;
    */
    while (x < n) {
        if (unknown()) {
            m = x;
        }
        x = x + 1;
    }

    //post-condition
    if(n > 1) {
       // @ assert m < n;
       // // @ assert m >= 1;
    }
}
