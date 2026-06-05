/*@
requires n > 0;
*/
void foo(int n)
{
    int x = 0;
    int m = 0;
    /*@
    loop invariant 0 <= x <= n;
    loop invariant m >= 0;
    loop invariant m < x;
    loop assigns x, m;
    */
    while (x < n) {
        if (unknown()) {
            m = x;
        }
        x = x + 1;
    }
    if(n > 0) {
       // @ assert m >= 0;
    }
}