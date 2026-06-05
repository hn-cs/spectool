int main()
{
	int x=0,y=500000,z=0;
	x=0;
	/*@
	loop invariant 0 <= x <= 1000000;
	loop invariant 500000 <= y <= 1000000;
	loop invariant z == 0;
	loop invariant y == 500000 + (x > 500000 ? x - 500000 : 0);
	loop assigns x, y, z;
	*/
	while(x<1000000){
		if(x<500000)
			x++;
		else{
			x++;
			y++;
		}
	}
	while(y>0){
		x--;
		z++;
		y=y-2;
	}
	// @ assert(x==z);
	return 0;
}
