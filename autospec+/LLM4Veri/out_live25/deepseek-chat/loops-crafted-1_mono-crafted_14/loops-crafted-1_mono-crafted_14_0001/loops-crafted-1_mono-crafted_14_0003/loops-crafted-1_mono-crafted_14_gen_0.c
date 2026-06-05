int main(){
	int x=0,y=500000,z=0;
	x=0;
	/*@
	loop invariant x + y/2 == 1000000;
	loop invariant z + y/2 == 500000;
	loop invariant y >= 0;
	loop invariant x == 1000000 - (500000 - z);
	loop invariant y%2 == 0;
	loop invariant y == 500000 || y == 500000 + (x - 500000);
	loop invariant x <= 1000000;
	loop invariant \at(z, Pre) == 0;
	loop invariant \at(y, Pre) == 500000;
	loop invariant \at(x, Pre) == 0;
	loop invariant 500000 <= y;
	loop invariant 1000000 - x;
	loop invariant 0 <= x;
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
	loop invariant z + y/2 == 500000;
	loop invariant y/2 <= 500000;
	loop invariant x + y/2 == 1000000;
	loop invariant 0 <= y;
	loop invariant 0 <= y/2;
	loop invariant 0 <= x;
	loop assigns z;
	loop assigns y;
	loop assigns x;
	*/
	while(y>0){
		x--;
		z++;
		y=y-2;
	}
	// @ assert(z%2==0);
	// @ assert(x%2==0);
	return 0;
}
