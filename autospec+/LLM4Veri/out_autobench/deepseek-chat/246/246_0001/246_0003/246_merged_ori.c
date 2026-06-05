#include <limits.h>
/*@
    ensures \result >= INT_MIN && \result <= INT_MAX;
*/
int unknown_int();

int main() {
    int i,j,k,n;

    k = unknown_int();
    n = unknown_int();
    if( k == n) {
    }
    else {
        goto END;
    }

    /*@
    loop invariant n - i;
    loop invariant i <= n;
    loop invariant \forall integer t; 0 <= t < i ==> \true;
    loop invariant 0 <= i;
    loop assigns k;
    loop assigns j;
    loop assigns i;
    */
    for (i = 0; i < n; i++) {
        /*@
        loop invariant n - i;
        loop invariant i <= n;
        loop invariant \forall integer t; 0 <= t < i ==> (\forall integer u; 2*t <= u < n ==> (unknown_int() ? (k <= u) : (k >= n && k <= n)));
        loop invariant 0 <= i;
        loop assigns k;
        loop assigns j;
        loop assigns i;
        */
        for (j= 2 * i; j < n; j++) {
            if( unknown_int()) {
                /*@
                loop invariant k <= n;
                loop invariant j <= k;
                loop invariant 2*i <= k;
                loop assigns k;
                */
                for (k = j; k < n; k++) {
                    // @ assert(k >= 2*i);
                }
            }
            else {
                // @ assert( k >= n );
                // @ assert( k <= n );
            }
        }
    }
END:
    return 0;
}