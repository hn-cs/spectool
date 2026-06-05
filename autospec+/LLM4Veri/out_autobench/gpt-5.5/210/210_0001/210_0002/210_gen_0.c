#include <stdio.h>

/*@
assigns \nothing;
ensures a < 0 ==> \result == 0;
ensures a >= 0 ==> \result == (a + 1) * b;
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