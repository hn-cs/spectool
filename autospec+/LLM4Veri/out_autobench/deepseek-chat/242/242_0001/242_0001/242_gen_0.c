// jm2006_variant_true-unreach-call.c
int main() {
    int i;
    int j;

    int x = i;
    int y = j;
    int z = 0;
    
    /*@
    loop invariant 0 <= x <= i;
    loop invariant y == j - 2*(i - x);
    loop invariant z == i - x;
    loop invariant i - x == z;
    loop invariant y == j - 2*z;
    loop assigns x, y, z;
    */
    while (x != 0) {
    	x--;
    	y -= 2;
    	z++;
    }

    if (i == j) {
    	// @ assert(y == -z);
    }
    
    return 0;
}
