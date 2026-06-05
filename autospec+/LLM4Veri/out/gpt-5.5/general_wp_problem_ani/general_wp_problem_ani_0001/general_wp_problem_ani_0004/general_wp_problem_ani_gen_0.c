#include <stdio.h>
/*@
assigns \nothing;
ensures n < 7 ==> \result == 1;
ensures n >= 7 ==> \result == (n + 2) / 3 - 1;
*/
int fun(int n) {
    int i = 7;
    int x = 1;
    /*@
    loop invariant x == 1 + (i - 7) / 3;
    loop invariant n >= 7 ==> i <= n + 3;
    loop invariant n < 7 ==> x == 1;
    loop invariant n < 7 ==> i == 7;
    loop invariant i == 7 + 3 * (x - 1);
    loop invariant i == 3 * x + 4;
    loop invariant 7 <= i;
    loop invariant 1 <= x;
    loop invariant (i - 7) % 3 == 0;
    loop assigns x;
    loop assigns i;
    */
    while(i <= n) {
        x += 1;
        i += 3;
    }
    return x;
}
int main() {
    int a = fun(10);
    // @ assert a == 3;
}