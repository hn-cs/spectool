#include <stdio.h>

/*@
requires b >= 0;
requires a >= 0;
assigns \nothing;
*/
int mul(int a, int b) {
    int x = a, y = b, prod = 0;

    /*@
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
    //@ assert pdt == 15;
}