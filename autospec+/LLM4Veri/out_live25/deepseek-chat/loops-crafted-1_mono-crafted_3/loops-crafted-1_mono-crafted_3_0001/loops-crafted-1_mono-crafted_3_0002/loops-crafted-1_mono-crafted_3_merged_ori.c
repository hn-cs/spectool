int main()
{
	int x=0,y=500000,z=0;
	x=0;
	/*@
	loop invariant z == 0;
	loop invariant y == 500000 + (x > 500000 ? x - 500000 : 0);
	loop invariant y <= 1000000;
	loop invariant x <= 1000000;
	loop invariant 500000 <= y;
	loop invariant 0 <= x;
	loop assigns z;
	loop assigns y;
	loop assigns x;
	*/
	while(x<1000000){
		if(x<500000)
			x++;
		else{
			x++;
			y++;
		}
	}
	/*@
	loop invariant z <= 500000;
	loop invariant y == 500000 - 2 * z;
	loop invariant x == 1000000 - z;
	loop invariant x + z == 1000000;
	loop invariant 0 <= z;
	loop invariant 0 <= y;
	loop assigns z;
	loop assigns y;
	loop assigns x;
	*/
	while(y>0){
		x--;
		z++;
		y=y-2;
	}
	// @ assert(x==z);
	return 0;
}
