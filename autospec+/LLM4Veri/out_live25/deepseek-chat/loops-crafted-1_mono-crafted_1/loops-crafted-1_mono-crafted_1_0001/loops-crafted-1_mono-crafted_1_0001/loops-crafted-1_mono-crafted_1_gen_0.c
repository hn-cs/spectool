int main()
{
	int x=0,y=50000,z=0;
	x=0;
	/*@
	loop invariant 0 <= x <= 1000000;
	loop invariant y == 50000 || y == 50000 + (x - 50000);
	loop invariant 0 <= x - y <= 50000;
	loop invariant z == 0;
	loop invariant \at(x, Pre) + \at(y, Pre) - \at(y, Pre) == x - y;
	loop assigns x, y;
	*/
	while(x<1000000){
		if(x<50000)
			x++;
		else{
			x++;
			y++;
		}
	}
	while(y>z){
		y--;
		x--;
	}
	// @ assert(x==z);
	return 0;
}
