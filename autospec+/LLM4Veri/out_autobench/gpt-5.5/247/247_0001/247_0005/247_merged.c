#include <limits.h>
/*@
    ensures \result >= INT_MIN && \result <= INT_MAX;
*/
int unknown_int();


int __BLAST_NONDET;

int main() {
    int i,j,k,n,l,m;

    n = unknown_int();
    m = unknown_int();
    l = unknown_int();
    if(3*n<=m+l); else goto END;
    /*@
    loop invariant n > 0 ==> i <= n;
    loop invariant n > 0 ==> 3 * i <= m + l;
    loop invariant n <= 0 || (0 <= i && i <= n);
    loop invariant n <= 0 ==> i == 0;
    loop invariant i == 0 || 0 < n;
    loop invariant 3 * n <= m + l;
    loop invariant 0 <= m + l - 3 * n;
    loop assigns i;
    */
    for (i=0;i<n;i++)
        /*@
        loop invariant j <= m + l;
        loop invariant j <= 3 * i;
        loop invariant j <= 3 * i || j <= m + l;
        loop invariant j <= 3 * i || 2 * i <= j;
        loop invariant j < m + l;
        loop invariant j < m + l;
        loop invariant j < 3 * i;
        loop invariant i <= j;
        loop invariant i <= j || j <= m + l;
        loop invariant i <= j || j <= 3 * i;
        loop invariant i <= j || 2 * i <= j;
        loop invariant i <= j || 0 <= j - 2 * i;
        loop invariant i <= j || 0 <= 3 * i - j;
        loop invariant i < j;
        loop invariant \forall integer k; i <= k < j ==> k - i <= 2 * n;
        loop invariant 2 * i <= j;
        loop invariant 2 * i <= j || j <= m + l;
        loop invariant 2 * i < j;
        loop invariant 0 <= j - 2 * i;
        loop invariant 0 <= j - 2 * i || j <= m + l;
        loop invariant 0 <= j - 2 * i || j <= 3 * i;
        loop invariant 0 <= j - 2 * i || 2 * i <= j;
        loop invariant 0 <= 3 * i - j;
        loop invariant 0 <= 3 * i - j || j <= m + l;
        loop invariant 0 <= 3 * i - j || j <= 3 * i;
        loop invariant 0 <= 3 * i - j || 2 * i <= j;
        loop invariant 0 <= 3 * i - j || 0 <= j - 2 * i;
        loop invariant 0 < j - 2 * i;
        loop invariant 0 < 3 * i - j;
        loop invariant 0 <= i;
        */
        for (j = 2*i;j<3*i;j++)
            for (k = i; k< j; k++)
                // @ assert( k-i <= 2*n );
END:
    return 0;
}