int main(){
	int x=0,y=500000,z=0;
	x=0;
	/*@
	loop invariant z == 0;
	loop invariant x >= 500000 ==> y == x;
	loop invariant x <= 500000 ==> y == 500000;
	loop invariant x <= 1000000;
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
	loop invariant z <= 500000;
	loop invariant y;
	loop invariant y == 1000000 - 2 * z;
	loop invariant y <= 1000000;
	loop invariant y % 2 == 0;
	loop invariant x == 1000000 - z;
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
	// @ assert(z%2==0);
	// @ assert(x%2==0);
	return 0;
}
