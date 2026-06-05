int main()
{
	int x=0,y=50000,z=0;
	x=0;
	/*@
	loop invariant z == 0;
	loop invariant y == 50000 || y == 50000 + (x - 50000);
	loop invariant x <= 1000000;
	loop invariant x - y <= 50000;
	loop invariant \at(x, Pre) + \at(y, Pre) - \at(y, Pre) == x - y;
	loop invariant 0 <= x;
	loop invariant 0 <= x - y;
	loop assigns y;
	loop assigns x;
	*/
	while(x<1000000){
		if(x<50000)
			x++;
		else{
			x++;
			y++;
		}
	}
	/*@
	loop invariant 0 <= z;
	loop invariant 0 <= x;
	loop invariant 0 <= y;
	loop invariant x - y == 1000000;
	loop invariant z == 0;
	loop invariant y <= 1050000;
	loop invariant x >= y;
	loop invariant \at(x, Pre) - x == 1000000 - x;
	loop assigns y;
	loop assigns x;
	*/
	while(y>z){
		y--;
		x--;
	}
	// @ assert(x==z);
	return 0;
}
