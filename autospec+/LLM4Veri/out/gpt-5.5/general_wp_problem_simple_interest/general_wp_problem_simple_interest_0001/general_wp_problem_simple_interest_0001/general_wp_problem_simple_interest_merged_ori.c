#include<limits.h>
/*@
requires INT_MIN <= p * n <= INT_MAX;
requires INT_MIN <= (p * n) * r <= INT_MAX;
ensures \result == (p * n * r) / 100;
assigns \nothing;
*/
int simple(int p,int n,int r)
{
    int si;
    si = p*n*r/100;
    return si;
}
int main()
{
    int s = simple(10000, 3,10);
    // @ assert s == 3000;
    return 0;
}