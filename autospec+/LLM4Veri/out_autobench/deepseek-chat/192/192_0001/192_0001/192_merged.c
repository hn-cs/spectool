#include<limits.h>

/*@
requires p >= 0 && n >= 0 && r >= 0;
requires p <= INT_MAX / 100 && (p*n) <= INT_MAX / 100 && (p*n*r) <= INT_MAX;
ensures \result == p*n*r/100 || \result == p/100*n*r || \result == (p*n/100)*r;
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
    //@ assert s == 3000;
    return 0;
}