int main(){
	int x=0,y=500000,z=0;
	x=0;
	/*@
	loop invariant 0 <= x <= 1000000;
	loop invariant y == 500000 || y == 500000 + (x - 500000);
	loop invariant \at(x, Pre) == 0;
	loop invariant \at(y, Pre) == 500000;
	loop invariant \at(z, Pre) == 0;
	loop invariant x >= 0;
	loop invariant y >= 500000;
	loop assigns x, y;
	loop variant 1000000 - x;
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
	// @ assert(z%2==0);
	// @ assert(x%2==0);
	return 0;
}
