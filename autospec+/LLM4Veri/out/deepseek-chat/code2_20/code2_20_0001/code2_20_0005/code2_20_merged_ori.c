/*@
requires n > 0;
*/
void foo(int n)
{
    int x = 0;
    int m = 0;
    /*@
    loop invariant -1 <= m;
    loop invariant (m >= 0) ==> unknown();
    loop invariant (m >= 0) ==> (\forall integer k; 0 <= k < m ==> !unknown());
    loop invariant (m == -1) ==> (\forall integer k; 0 <= k < x ==> !unknown());
    loop invariant x <= n;
    loop invariant m == -1 || (0 <= m < x && unknown() at iteration m);
    loop invariant m <= n;
    loop invariant m <= n;
    loop invariant m <= n;
    loop invariant m <= n;
    loop invariant m <= n;
    loop invariant m <= n;
    loop invariant m <= n;
    loop invariant m <= n;
    loop invariant m <= n;
    loop invariant m <= n;
    loop invariant m <= n;
    loop invariant m <= n;
    loop invariant m < x;
    loop invariant m < n;
    loop invariant \forall integer k; 0 <= k <= x ==> (k == m ==> unknown() at iteration m);
    loop invariant \forall integer k; 0 <= k < x ==> (unknown() at iteration k ==> m == k);
    loop invariant \forall integer k; 0 <= k < x && unknown() at iteration k ==> m == k;
    loop invariant \exists integer k; 0 <= k < x && m == k;
    loop invariant \exists integer k; 0 <= k < x && m == k && unknown() at iteration k;
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
       // @ assert m < n;
       // @ assert m >= 0;
    }
}