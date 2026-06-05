/*@
	requires n >= 0;
*/
void foo(int n){
	int x = n;
	int y = 0;

	/*@
	loop invariant y == n - x;
	loop invariant x;
	loop invariant x <= n;
	loop invariant 0 <= x;
	loop assigns y;
	loop assigns x;
	*/
	while (x > 0) {
		x--;
		y++;
	}

	// @ assert(y == n);
}
