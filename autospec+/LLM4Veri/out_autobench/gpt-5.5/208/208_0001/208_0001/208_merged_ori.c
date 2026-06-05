#include <stdio.h>
#include <math.h>

int fun(int n) {
    double y = 0;
    double i = 0;

    /*@
    loop invariant n + 1 - i;
    loop invariant i <= n + 1;
    loop invariant 0 <= y;
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