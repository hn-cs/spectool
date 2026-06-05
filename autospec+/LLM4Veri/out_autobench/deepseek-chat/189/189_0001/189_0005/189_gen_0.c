/*@
requires a >= 0 && b >= 0;
requires !(a == 0 && b == 0);
ensures \result == \old(a) > 0 || \old(b) > 0 ? 
         (\exists integer d; d > 0 && \old(a) % d == 0 && \old(b) % d == 0 && 
          (\forall integer e; e > 0 && \old(a) % e == 0 && \old(b) % e == 0 ==> e <= d)) : 
         \old(a) == 0 ? \old(b) : \old(a);
ensures \result > 0;
assigns \nothing;
*/
int gcd(int a, int b) {
    if (a == 0)
       return b;

    if (b == 0)
       return a;

    if (a == b)
        return a;

    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int main()
{
    int a = 98, b = 56;
    int c = gcd(a, b);
    // @ assert c == 14;
    return 0;
}