int main()
{
	int x=0,y=50000,z=0;
	x=0;
	/*@
	loop invariant z == 0;
	loop invariant y == (x <= 50000 ? 50000 : x);
	loop invariant x <= 1000000;
	loop invariant 0 <= x;
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
	loop invariant x == y;
	loop invariant z == 0;
	loop invariant y >= z;
	loop assigns x, y;
	loop variant y - z;
	*/
	while(y>z){
		y--;
		x--;
	}
	// @ assert(x==z);
	return 0;
}
