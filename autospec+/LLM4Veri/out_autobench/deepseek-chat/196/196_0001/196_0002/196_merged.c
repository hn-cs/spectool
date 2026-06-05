/*@
requires y >= 5 && y <= 15;
requires x >= -5 && x <= 5;
ensures x - y + 5 <= \result <= x + y + 15;
assigns \nothing;
*/
int function(int x, int y) {
    int res ;
    y += 10 ;
    x -= 5 ;
    res = x + y ;
    //@ assert -15 <= res <= 5;
    return res ;
}

// write a test
void main() {
    int t = function(-5, 5);
    //@ assert t == 5;
}