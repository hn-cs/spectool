int main()
{
	int x = 0;
	int y = 500000;
	/*@
	loop invariant x >= 500000 ==> y == x;
	loop invariant x <= 500000 ==> y == 500000;
	loop invariant x <= 1000000;
	loop invariant 1000000 - x;
	loop invariant 0 <= x;
	loop assigns y;
	loop assigns x;
	*/
	while(x < 1000000) {
		if (x < 500000) {
			x = x + 1;
		} else {
			x = x + 1;
			y = y + 1;
		}
	}
	// @ assert(y==x);
	return 0;
}
