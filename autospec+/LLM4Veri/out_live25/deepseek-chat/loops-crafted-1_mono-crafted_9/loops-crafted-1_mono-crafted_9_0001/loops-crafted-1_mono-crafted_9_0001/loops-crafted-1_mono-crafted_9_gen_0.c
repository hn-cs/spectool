int main()
{
	int x = 0;
	int y = 500000;
	/*@
	loop invariant 0 <= x <= 1000000;
	loop invariant x <= y;
	loop invariant y - x == 500000;
	loop invariant y >= 500000;
	loop assigns x, y;
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
