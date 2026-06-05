#include <stdlib.h>
int sum(char n) {
    int s = 0;
    char k = 0;
    /*@
    loop invariant 0 <= k <= n+1;
    loop invariant s == (int)((k)*(k-1)/2);
    loop assigns s, k;
    loop variant n - k;
    */
    while(k <= n) {    
        s = s + (int)k;
        k = k + 1;
    }
    // @ assert s == (int)((n+1)*(n)/2);
    return (int)s;
}
int main() {
    int s = sum(5);
    // @ assert s == 15;
}