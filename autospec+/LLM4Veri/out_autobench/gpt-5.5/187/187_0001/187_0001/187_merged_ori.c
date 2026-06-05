#include <stdio.h>

int fun(int n) {
    int i = 7;
    int x = 1;

    /*@
    loop invariant n - i;
    loop invariant i == 3 * x + 4;
    loop invariant i <= n + 3;
    loop invariant 7 <= i;
    loop invariant 1 <= x;
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