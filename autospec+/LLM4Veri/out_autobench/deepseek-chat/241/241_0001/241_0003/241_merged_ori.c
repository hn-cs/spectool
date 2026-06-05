// hhk2008_true-unreach-call.c
int main() {
    int a;
    int b;
    
    int res, cnt;

    res = a;
    cnt = b;
    
    /*@
    loop invariant res - a == b - cnt;
    loop invariant 0 <= cnt;
    loop invariant 0 < cnt;
    loop invariant 0 < cnt;
    loop invariant 0 < cnt;
    loop invariant 0 < cnt;
    loop invariant 0 < cnt;
    loop invariant 0 < cnt;
    loop invariant 0 < cnt;
    loop invariant res == a + (b - cnt);
    loop invariant res + cnt == a + b;
    loop invariant cnt <= b;
    loop invariant a <= res;
    loop assigns res;
    loop assigns cnt;
    */
    while (cnt > 0) {
    	cnt = cnt - 1;
        res = res + 1;
    }

    // @ assert(res == a + b);
    
    return 0;
}
