// sum01_true-unreach-call_true-termination.c
int main() {
    int n;
    int i=0;
    int sn=0;
    
    /*@
    loop invariant sn == 2 * i - 2;
    loop invariant i >= 1 ==> sn == 2 * (i - 1);
    loop invariant i <= n + 1;
    loop invariant i < n + 1;
    loop invariant i < n + 1;
    loop invariant i < n + 1;
    loop invariant i < n + 1;
    loop invariant i < n + 1;
    loop invariant i < n + 1;
    loop invariant i < n + 1;
    loop invariant i < n + 1;
    loop invariant sn == 2 * (i - 1);
    loop invariant sn == (i-1) * 2;
    loop invariant sn % 2 == 0;
    loop invariant 1 <= i;
    loop invariant 0 <= sn;
    loop assigns sn;
    loop assigns i;
    */
    for (i = 1; i <= n; i++) {
        sn = sn + (2);
    }
    
    // @ assert(sn == n * (2) || sn == 0);
    
    return 0;
}
