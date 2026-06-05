// bhmr2007_true-unreach-call.c
// Source: Dirk Beyer, Thomas A. Henzinger, Rupak Majumdar, Andrey
// Rybalchenko: "Path Invariants", PLDI 2007.
int main() {
    int i, n, a, b;
    i = 0; a = 0; b = 0;
    
    /*@
    loop invariant n <= 0 || i <= n;
    loop invariant i <= a + b;
    loop invariant a <= b + i;
    loop invariant b <= a + i;
    loop invariant (a + b) % 3 == 0;
    loop invariant a == 3 * i - b;
    loop invariant b == 3 * i - a;
    loop invariant n >= 0 ==> a + b <= 3 * n;
    loop invariant i == 0 || i <= n;
    loop invariant i <= b;
    loop invariant i <= a;
    loop invariant b <= 2 * i;
    loop invariant a <= 2 * i;
    loop invariant a - b <= i;
    loop invariant a + b == 3 * i;
    loop invariant 0 <= i;
    loop invariant 0 <= b;
    loop invariant 0 <= a;
    loop invariant -i <= a - b;
    loop invariant (a - b - i) % 2 == 0;
    loop assigns i;
    loop assigns b;
    loop assigns a;
    */
    while (i < n) {
        int boolean;
        if (boolean != 0) {
            a = a + 1;
            b = b + 2;
        } else {
            a = a + 2;
            b = b + 1;
        }
        i = i + 1;
    }

    // @ assert(a + b == 3 * n);
    
    return 0;
}
