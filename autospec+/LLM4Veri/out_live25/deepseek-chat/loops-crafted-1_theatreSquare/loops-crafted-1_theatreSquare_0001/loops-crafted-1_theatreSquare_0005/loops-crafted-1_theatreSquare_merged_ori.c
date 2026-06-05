#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
/*@
requires n >= 0;
requires m >= 0;
requires a > 0;
ensures \result == ((n + a - 1) / a) * ((m + a - 1) / a);
assigns \nothing;
*/
int correct_version(int n, int m, int a)
{
    int i = 0, j = 0, b = 0, l = 0;
    /*@
    loop invariant b == a * i;
    loop invariant 0 <= i;
    loop assigns i;
    loop assigns b;
    */
    while(b < n)
    {
        b = b + a;
        i = i + 1;
    }
    /*@
    loop invariant l <= m;
    loop invariant j == (l / a);
    loop invariant j * a == l;
    loop invariant i == (n + a - 1) / a; /* ceiling of n/a;
    loop invariant b == a * i;
    loop invariant 0 <= l;
    loop assigns l;
    loop assigns j;
    */
    while(l < m)
    {
        l = l + a;
        j = j + 1;
    }
    int x = 0, y = 0;
    /*@
    loop invariant y == j * x;
    loop invariant x <= i;
    loop invariant 0 <= x;
    loop assigns y;
    loop assigns x;
    */
    while(x < i)
    {
        y = y + j;
        x = x + 1;
    }
    return y;
}
int student_version(int n, int m, int a)
{
    int i = 0, j = 0, b = 0, l = 0;
    /*@
    loop invariant b == a * i;
    loop invariant 0 <= i;
    loop assigns i;
    loop assigns b;
    */
    while(b < n)
    {
        b = b + a;
        i = i + 1;
    }
    while(l < m)
    {
        l = l + a;
        j = j + 1;
    }
    int x = 0, y = 0;
    while(x < i)
    {
        y = y + j;
        x = x + 1;
    }
    return y;
}
int main()
{
    int a=unknown(), n=unknown(), m=unknown();
    int n_stones1, n_stones2=unknown();
    n_stones1 = n_stones2;
    if((1 <= n) &&
       (1 <= m) &&
       (1 <= a) &&
       (n <= 109) &&
       (m <= 109) &&
       (a <= 109))
    {
        n_stones1 = correct_version(n, m, a);
        n_stones2 = student_version(n, m, a);
    }
    // @ assert(n_stones1 == n_stones2);
    return 0;
}
