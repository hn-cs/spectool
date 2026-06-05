int main()
{
	int x=0,y=500000,z=0;
	x=0;
	/*@
	loop invariant 0 <= x <= 1000000;
	loop invariant x <= 500000 ==> y == 500000;
	loop invariant x > 500000 ==> 500000 + (x - 500000) <= y;
	loop invariant x <= 500000 ==> z == 0;
	loop invariant x > 500000 ==> z <= x;
	loop assigns x, y, z;
	loop variant 1000000 - x;
	*/
	while(x<1000000){
		if(x<500000)
			x++;
		else{
			if(x<750000){
				x++;
			}
			else{
				x=x+2;
			}
			y++;
		}
	}
	 // @ assert(x==1000000);
	return 0;
}
