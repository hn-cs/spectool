#include <stdio.h>

int mul(int a, int b) {
    int x = a, y = b, prod = 0;

    /*@
    loop invariant x == a - (prod/b);
    loop invariant \exists integer k; 0 <= k <= a && prod == k * b;
    loop invariant -1 <= x;
    loop invariant -1 < x;
    loop invariant y == b;
    loop invariant x <= a;
    loop invariant x <= a + 1;
    loop invariant prod == (a - x) * b;
    loop assigns x;
    loop assigns prod;
    */
    while(x >= 0) {
        prod = prod + y;
        x--;
    }
    return prod;
}

int main() {
    int pdt = mul(2, 5);
    // @ assert pdt == 15;
}