int main()
{
    int z1,z2,z3;
    int x = 1;
    int m = 1;
    int n;
    /*@
    loop invariant m >= 1 ==> x >= m;
    loop invariant m == x ==> \forall integer k; 0 <= k < x ==> k < m;
    loop invariant m <= x;
    loop invariant \forall integer k; 0 <= k < x ==> m <= k || m >= k;
    loop invariant \exists integer k; k == x - m;
    loop invariant 1 <= x || m <= x;
    loop invariant 1 <= m;
    loop invariant 0 <= x;
    loop assigns x;
    loop assigns m;
    loop invariant m >= 1 ==> x >= m;
    loop invariant m == x ==> \forall integer k; 0 <= k < x ==> k < m;
    loop invariant m <= x;
    loop invariant \forall integer k; 0 <= k < x ==> m <= k || m >= k;
    loop invariant \exists integer k; k == x - m;
    loop invariant 1 <= x || m <= x;
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
    if(n > 1) {
       // @ assert m < n;
       // @ assert m >= 1;
    }
}