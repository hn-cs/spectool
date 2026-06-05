int main() {
    int i;
    int j;

    int x = i;
    int y = j;
    /*@
    loop invariant 0 <= x <= \at(x, Pre);
    loop invariant y - x == \at(y, Pre) - \at(x, Pre);
    loop assigns x, y;
    */
    while (x != 0) {
    	x--;
    	y--;
    }

    if (i == j) {
    	// @ assert(y == 0);
    }
    
    return 0;
}
