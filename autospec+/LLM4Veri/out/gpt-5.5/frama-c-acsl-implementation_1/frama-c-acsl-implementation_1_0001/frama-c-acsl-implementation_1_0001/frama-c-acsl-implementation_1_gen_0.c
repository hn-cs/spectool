/*@
requires n > 0 ==> \valid(p);
requires n <= 0 ==> \valid(q);
assigns n > 0 ? *p : *q;
ensures n > 0 ==> *p == n;
ensures n <= 0 ==> *q == n;
*/
void f(int n, int *p, int *q) {
    if (n > 0) *p = n;
    else *q = n;
}
int main(){
    int n = 10;
    int p = 1,q = 2;
    f(n, &p, &q);
    // @ assert p == 10;
    n = -10;
    f(n, &p, &q);
    // @ assert q == -10;
}