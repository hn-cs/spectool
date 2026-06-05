#include <stdio.h>

int fun(int n) {
    int i = 7;
    int x = 1;

    /*@
    loop invariant i <= n+3;
    loop invariant i < n+3;
    loop invariant i < n+3;
    loop invariant i < n+3;
    loop invariant i < n+3;
    loop invariant i < n+3;
    loop invariant i < n+3;
    loop invariant 1 <= x;
    loop invariant 1 <= x || i <= n+3;
    loop invariant 1 < x;
    loop invariant x == (i - 7) / 3 + 1;
    loop invariant i == 7 + 3*(x-1);
    loop invariant 7 <= i;
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