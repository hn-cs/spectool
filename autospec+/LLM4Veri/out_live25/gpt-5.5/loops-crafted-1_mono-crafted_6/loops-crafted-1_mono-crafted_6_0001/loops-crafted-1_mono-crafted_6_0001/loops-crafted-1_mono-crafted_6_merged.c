int main()
{
	int x=0,y=500000,z=0;
	x=0;
	/*@
	loop invariant z == 0;
	loop invariant x <= 1000000;
	loop invariant x < 750000 || x % 2 == 0;
	loop invariant 0 <= x;
	loop assigns y;
	loop assigns x;
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
	 //@ assert(x==1000000);
	return 0;
}
