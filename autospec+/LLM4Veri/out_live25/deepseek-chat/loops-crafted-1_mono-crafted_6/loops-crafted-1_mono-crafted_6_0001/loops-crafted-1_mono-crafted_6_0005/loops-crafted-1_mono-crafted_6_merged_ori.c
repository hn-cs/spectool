int main()
{
	int x=0,y=500000,z=0;
	x=0;
	/*@
	loop invariant y == 500000 + (x > 500000 ? x - 500000 : 0);
	loop invariant x == 1000000 ==> z == 250000;
	loop invariant x % 2 == 0;
	loop invariant z == 0;
	loop invariant x > 500000 ==> z <= x;
	loop invariant x == 0 ==> y == 500000;
	loop invariant x <= 500000 ==> z == 0;
	loop invariant x <= 500000 ==> y == 500000;
	loop invariant \forall integer k; 0 <= k <= x ==> 1 == 1;
	loop invariant 0 <= x;
	loop assigns z;
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
	 // @ assert(x==1000000);
	return 0;
}
