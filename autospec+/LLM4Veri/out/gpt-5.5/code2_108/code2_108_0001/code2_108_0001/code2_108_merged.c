/*@
requires a <= m;
*/
void foo(int a, int m, int c) {
    int j = 0;
    int k = 0;
    /*@
    loop invariant c >= 0 ==> k <= c;
    loop invariant a <= m;
    loop invariant 0 <= k;
    loop assigns m;
    loop assigns k;
    */
    while (k < c) {
        if(m < a) {
            m = a;
        }
        k = k + 1;
    }
    //@ assert a <= m;
}