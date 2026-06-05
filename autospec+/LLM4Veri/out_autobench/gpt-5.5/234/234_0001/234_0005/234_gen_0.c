// bhmr2007_true-unreach-call.c
// Source: Dirk Beyer, Thomas A. Henzinger, Rupak Majumdar, Andrey
// Rybalchenko: "Path Invariants", PLDI 2007.
int main() {
    int i, n, a, b;
    i = 0; a = 0; b = 0;
    
    /*@
    <think>**Exploring mathematical conditions**
    
    I'm looking at conditions where both a and b must be less than or equal to 3i when added together. I also notice that both a and b can be at most 2i and at least i. There’s something interesting about the existing relation with i, especially when I consider the quotient a/b. I could also think about adding more criteria, like a being less than or equal to 2*i, and b following the same pattern, but I'm cautious about possible duplicates.</think>
    
    loop invariant a >= i && b >= i;
    loop invariant a <= 2 * i && b <= 2 * i;
    loop invariant a + b - 3 * i == 0;
    loop invariant 3 * i - a == b;
    loop invariant 3 * i - b == a;
    loop invariant a - i <= b;
    loop invariant b - i <= a;
    loop invariant a <= 2 * i && i <= a;
    loop invariant b <= 2 * i && i <= b;
    loop invariant n < i ==> i == 0;
    loop invariant n >= 0 ==> b <= 2 * n;
    loop invariant n >= 0 ==> a <= 2 * n;
    loop invariant n >= 0 ==> a + b <= 3 * n;
    loop invariant n <= 0 || i <= n;
    loop invariant n < 0 ==> i == 0;
    loop invariant i == 0 || i <= n;
    loop invariant i <= b;
    loop invariant i <= a;
    loop invariant i <= a + b;
    loop invariant i <= a + b || a <= b + i;
    loop invariant b == 3 * i - a;
    loop invariant b <= a + i;
    loop invariant b <= a + i || i <= a + b;
    loop invariant b <= a + i || a <= b + i;
    loop invariant b <= a + b;
    loop invariant b <= a + b || a <= a + b;
    loop invariant b <= a + b || 0 <= a + b;
    loop invariant b <= 2 * i;
    loop invariant b <= 2 * a;
    loop invariant b <= 2 * a || b <= a + b;
    loop invariant b <= 2 * a || a <= a + b;
    loop invariant b <= 2 * a || a <= 2 * b;
    loop invariant b <= 2 * a || 0 <= a + b;
    loop invariant a == 3 * i - b;
    loop invariant a <= b + i;
    loop invariant a <= a + b;
    loop invariant a <= 2 * i;
    loop invariant a <= 2 * b;
    loop invariant a <= 2 * b || b <= a + b;
    loop invariant a <= 2 * b || a <= a + b;
    loop invariant a <= 2 * b || 0 <= a + b;
    loop invariant a - b <= i;
    loop invariant a + b == 3 * i;
    loop invariant 0 <= i;
    loop invariant 0 <= b;
    loop invariant 0 <= a;
    loop invariant 0 <= a + b;
    loop invariant 0 <= a + b || a <= a + b;
    loop invariant -i <= a - b;
    loop invariant (a - b - i) % 2 == 0;
    loop invariant (a - b + i) % 2 == 0;
    loop invariant (a + b) % 3 == 0;
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
