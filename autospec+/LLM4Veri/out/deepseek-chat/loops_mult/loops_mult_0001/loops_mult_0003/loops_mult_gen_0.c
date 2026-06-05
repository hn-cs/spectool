#include <stdio.h>
int mul(int a, int b) {
    int x = a, y = b, prod = 0;
    /*@
    loop invariant prod == (a - x - 1) * b;
    loop invariant x <= a;
    loop invariant 0 <= x;
    loop invariant x + 1 == a - (a - x - 1);
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