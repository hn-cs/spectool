// sum01_true-unreach-call_true-termination.c
int main() {
    int n;
    int i=0;
    int sn=0;
    
    /*@
    loop invariant sn % 2 == 0;
    loop invariant n < 1 ==> i == 1 && sn == 0;
    loop invariant i == sn / 2 + 1;
    loop invariant i == 1 || i <= n + 1;
    loop invariant 0 <= sn;
    loop invariant sn == 2 * (i - 1);
    loop invariant 1 <= i;
    loop assigns sn;
    loop assigns i;
    */
    for (i = 1; i <= n; i++) {
        sn = sn + (2);
    }
    
    //@ assert(sn == n * (2) || sn == 0);
    
    return 0;
}
