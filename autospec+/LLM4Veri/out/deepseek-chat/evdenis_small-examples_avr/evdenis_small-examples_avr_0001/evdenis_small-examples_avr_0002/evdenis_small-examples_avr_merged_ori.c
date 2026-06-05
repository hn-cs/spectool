/*@
requires INT_MIN <= b - a <= INT_MAX;
requires INT_MIN <= a - b <= INT_MAX;
requires INT_MIN <= a + b <= INT_MAX;
ensures \result == (a + b) / 2;
assigns \nothing;
*/
int avr(int a, int b)
{
	int avr;
	if (a >= 0 && b >= 0) {
		if (b > a) {
			avr = a + (b - a) / 2;
		} else {
			avr = b + (a - b) / 2;
		}
	} else if (a < 0 && b < 0) {
		if (b > a) {
			avr = b + (a - b) / 2;
		} else {
			avr = a + (b - a) / 2;
		}
	} else {
		avr = (a + b) / 2;
	}
	return avr;
}
int main(){
	int a = 10;
	int b = 20;
	int c = avr(a,b);
	// @ assert c == 15;
}