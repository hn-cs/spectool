// hhk2008_true-unreach-call.c
int main() {
    int a;
    int b;
    
    int res, cnt;

    res = a;
    cnt = b;
    
    /*@
    loop invariant 0 <= cnt <= b;
    loop invariant res == a + (b - cnt);
    loop invariant cnt >= 0;
    loop assigns cnt, res;
    */
    while (cnt > 0) {
    	cnt = cnt - 1;
        res = res + 1;
    }

    // @ assert(res == a + b);
    
    return 0;
}
