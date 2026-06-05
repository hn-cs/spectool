// hhk2008_true-unreach-call.c
int main() {
    int a;
    int b;
    
    int res, cnt;

    res = a;
    cnt = b;
    
    /*@
    loop invariant res > a ==> cnt < b;
    loop invariant res == a ==> cnt == b;
    loop invariant cnt < b || res == a;
    loop invariant cnt < b ==> res > a;
    loop invariant (res + cnt) % 2 == (a + b) % 2;
    loop invariant res == a + b - cnt;
    loop invariant res == a + (b - cnt);
    loop invariant res - a == b - cnt;
    loop invariant res + cnt == a + b;
    loop invariant cnt > 0 ==> res < a + b;
    loop invariant cnt == b ==> res == a;
    loop invariant cnt == a + b - res;
    loop invariant cnt <= b;
    loop invariant cnt < 0 ==> res == a && cnt == b;
    loop invariant a <= res;
    loop assigns res;
    loop assigns cnt;
    */
    while (cnt > 0) {
    	cnt = cnt - 1;
        res = res + 1;
    }

    //@ assert(res == a + b);
    
    return 0;
}
