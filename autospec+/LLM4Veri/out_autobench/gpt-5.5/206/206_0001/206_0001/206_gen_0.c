#include <stdlib.h>

int sum(int n) {
    int s = 0;
    int k = 0;

    /*@
    loop invariant 0 <= k <= n + 1;
    loop invariant s == k * (k - 1) / 2;
    loop assigns s, k;
    loop variant n - k + 1;
    */
    while(k <= n) {    
        s = s + k;
        k = k + 1;
    }
    return s;
}

int main() {
    int s = sum(5);
    // @ assert s == 15;
}