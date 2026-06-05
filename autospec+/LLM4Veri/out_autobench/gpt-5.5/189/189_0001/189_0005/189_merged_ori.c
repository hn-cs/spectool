/*@
requires a >= 0 && b >= 0;
requires a > 0 || b > 0;
predicate divides(integer d, integer n) = d > 0 && n % d == 0;;
ensures divides(\result, b);
ensures divides(\result, a);
ensures a == 98 && b == 56 ==> \result == 14;
ensures \result > 0;
ensures \forall integer d; divides(d, a) && divides(d, b) ==> d <= \result;
decreases a + b;
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