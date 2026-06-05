/*@
requires a >= 0 && b >= 0;
requires !(a == 0 && b == 0);
ensures a % \result == 0 && b % \result == 0;
ensures \result > 0;
ensures \forall integer z; z > 0 && a % z == 0 && b % z == 0 ==> \result % z == 0;
ensures (a == 0 ==> \result == b) && (b == 0 ==> \result == a);
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