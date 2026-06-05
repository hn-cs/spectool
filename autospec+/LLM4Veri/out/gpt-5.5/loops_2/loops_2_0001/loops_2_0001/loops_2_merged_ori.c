#include <stdlib.h>
int sum(char n) {
    int s = 0;
    char k = 0;
    /*@
    loop invariant s == ((int)k * ((int)k - 1)) / 2;
    loop invariant n >= 0 ==> k <= n + 1;
    loop invariant n - k + 1;
    loop invariant 0 <= k;
    loop assigns s;
    loop assigns k;
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