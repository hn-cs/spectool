int main()
{
    int x = 1;
    int m = 1;
    int n;
    /*@
    loop invariant 1 <= x <= n;
    loop invariant 1 <= m < x;
    loop invariant m >= 1;
    loop assigns x, m;
    loop variant n - x;
    */
    while (x < n) {
        if (unknown()) {
            m = x;
        }
        x = x + 1;
    }
    if(n > 1) {
       //// @ assert m < n;
       // @ assert m >= 1;
    }
}