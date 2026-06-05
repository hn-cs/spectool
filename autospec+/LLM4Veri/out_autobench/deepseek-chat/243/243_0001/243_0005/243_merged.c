int main() {
    int i;
    int j;

    int x = i;
    int y = j;
    /*@
    loop invariant x == 0 ==> y == \at(y, Pre) - \at(i, Pre);
    loop invariant x <= \at(x, Here);
    loop invariant 0 <= y;
    loop invariant 0 <= \at(x, Pre);
    loop invariant y - x == \at(y, Pre) - \at(x, Pre);
    loop invariant x == y;
    loop invariant x == y - (\at(y, Pre) - \at(x, Pre));
    loop invariant x <= y;
    loop invariant x <= \at(x, Pre);
    loop invariant x < y;
    loop invariant x < y;
    loop invariant x < y;
    loop invariant x < y;
    loop invariant x < y;
    loop invariant x < y;
    loop invariant x < y;
    loop invariant x < y;
    loop invariant \at(y, Pre) - \at(x, Pre) == y - x;
    loop invariant 0 <= x;
    loop assigns y;
    loop assigns x;
    */
    while (x != 0) {
    	x--;
    	y--;
    }

    if (i == j) {
    	//@ assert(y == 0);
    }
    
    return 0;
}
