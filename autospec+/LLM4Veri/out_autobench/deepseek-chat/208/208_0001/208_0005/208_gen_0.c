#include <stdio.h>
#include <math.h>

int fun(int n) {
    double y = 0;
    double i = 0;

    /*@
    loop invariant y + pow(2.0, i) == pow(2.0, i + 1) - 1;
    loop invariant y == (pow(2.0, (int)i) - 1);
    loop invariant (int)i == i;
    loop invariant y == (pow(2.0, i) - 1);
    loop invariant i == (int)i;
    loop invariant i <= n+1;
    loop invariant 0 <= i;
    loop assigns y;
    loop assigns i;
    */
    while(i <= n) {
        y = y + pow(2.0, i);
        i = i + 1;
    }
    return y;
}

int main() {
    int res = fun(4);
    //@assert res == 7;
}