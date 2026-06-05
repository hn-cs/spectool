int main() {
    int i;
    int j;

    int x = i;
    int y = j;
    /*@
    loop invariant y - x == \at(y, Pre) - \at(x, Pre);
    loop invariant x <= \at(x, Pre);
    loop invariant 0 <= x;
    loop assigns y;
    loop assigns x;
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
