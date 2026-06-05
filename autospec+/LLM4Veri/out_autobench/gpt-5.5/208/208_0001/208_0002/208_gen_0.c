#include <stdio.h>
#include <math.h>

/*@
requires 0 <= n <= 13;
  assigns \nothing;
  ensures \result == (1 << (n + 1)) - 1;
*/
int fun(int n) {
    double y = 0;
    double i = 0;

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