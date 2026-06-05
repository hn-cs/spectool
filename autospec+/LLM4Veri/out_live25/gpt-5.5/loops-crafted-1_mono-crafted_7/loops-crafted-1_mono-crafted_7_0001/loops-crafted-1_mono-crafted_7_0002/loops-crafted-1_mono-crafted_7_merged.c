int main()
{
	int x=0,y=50000,z=0;
	x=0;
	/*@
	loop invariant z == 0;
	loop invariant y <= 1000000;
	loop invariant x >= 50000 ==> y == x;
	loop invariant x <= 50000 ==> y == 50000;
	loop invariant x <= 1000000;
	loop invariant 50000 <= y;
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
	loop invariant z == 0;
	loop invariant y <= 1000000;
	loop invariant y % 2 == 0;
	loop invariant x == y;
	loop invariant 0 <= y;
	loop assigns y;
	loop assigns x;
	*/
	while(y>0){
		y=y-2;
		x=x-2;
	}
	 //@ assert(z==x);
	return 0;
}
