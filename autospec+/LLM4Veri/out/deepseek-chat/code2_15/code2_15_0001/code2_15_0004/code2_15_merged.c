/*@
requires n > 0;
*/
void foo(int n)
{
    int x = 0;
    int m = 0;
    /*@
    loop invariant x <= n;
    loop invariant m == n-1 ==> x == n;
    loop invariant m == \old(m) || m == x - 1;
    loop invariant m == -1 ==> x == 1;
    loop invariant m <= n;
    loop invariant m < x;
    loop invariant \forall integer k; 0 <= k < x ==> m >= k || m == 0;
    loop invariant 0 <= x;
    loop invariant 0 <= m;
    loop assigns x;
    loop assigns m;
    */
    while (x < n) {
        if (unknown()) {
            m = x;
        }
        x = x + 1;
    }
    if(n > 0) {
       //@ assert m < n;
       //@ assert m >= 0;
    }
}