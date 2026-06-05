//terminator_03_true-unreach-call_true-termination.c
int main() {
	int x;
	int y;
	if (y > 0) {
		/*@
		loop invariant x <= 100;
		loop invariant x <= 100 ==> (x - 100) % y == 0;
		loop invariant 0 <= x;
		loop invariant 0 < y;
		loop invariant (100 - x) / y + 1;
		loop assigns x;
		*/
		while (x < 100) {
			x = x + y;
		}
	}
	

	// @ assert(y <= 0 || (y > 0 && x >= 100));

	return 0;
}
