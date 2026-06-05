/*@
requires n > 1;
*/
void foo(int n)
{
    int x = 1;
    int m = 1;

    /*@
    loop invariant x <= n;
    loop invariant m <= n;
    loop invariant m < x;
    loop invariant m < n;
    loop invariant 1 <= m;
    loop invariant 0 <= x;
    loop assigns x;
    loop assigns m;
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
