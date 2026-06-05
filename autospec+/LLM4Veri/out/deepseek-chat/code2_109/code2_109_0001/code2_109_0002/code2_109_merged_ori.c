/*@
requires c>0;
*/
void foo(int a, int m, int c) {
    int j = 0;
    int k = 0;
    /*@
    loop invariant m >= a || k == 0;
    loop invariant m == \max(0, a);
    loop invariant \forall integer i; 0 <= i < k ==> m >= a;
    loop invariant k <= c;
    loop invariant 0 <= k;
    loop assigns m;
    loop assigns k;
    */
    while ( k < c) {
        if(m < a) {
            m = a;
        }
        k = k + 1;
    }
    if(c > 0) {
        // @ assert a <=  m;
    }
}