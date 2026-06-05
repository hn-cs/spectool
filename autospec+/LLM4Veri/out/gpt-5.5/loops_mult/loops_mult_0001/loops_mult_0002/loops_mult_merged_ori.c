#include <stdio.h>
/*@
requires a < 0 || -2147483648 <= (a + 1) * b <= 2147483647;
ensures a >= 0 ==> \result == (a + 1) * b;
ensures a < 0 ==> \result == 0;
assigns \nothing;
*/
int mul(int a, int b) {
    int x = a, y = b, prod = 0;
    /*@
    loop invariant y == b;
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