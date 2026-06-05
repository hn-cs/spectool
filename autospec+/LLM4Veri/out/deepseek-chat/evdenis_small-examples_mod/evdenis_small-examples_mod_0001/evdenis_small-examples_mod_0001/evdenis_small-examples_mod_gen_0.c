/*@
requires b != 0;
ensures \result == a - (a / b) * b;
ensures 0 <= \result < b || b < \result <= 0;
assigns \nothing;
*/
int mod(int a, int b)
{
	return a % b;
}
int main(){
    int a = 10000;
    int b = 3;
    int c = mod(a,b);
    // @ assert c == 1;
}