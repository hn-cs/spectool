/*@
requires -2147483648 <= x <= 2147483647;
requires -2147483648 <= y <= 2147483647;
ensures \result == (x - 5) + (y + 10);
assigns \nothing;
*/
int function(int x, int y) {
    int res ;
    y += 10 ;
    x -= 5 ;
    res = x + y ;
    // @ assert -15 <= res <= 5;
    return res ;
}

// write a test
void main() {
    int t = function(-5, 5);
    // @ assert t == 5;
}