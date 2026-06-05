int main(){
	int x=0,y=50000,z=0;
	x=0;
	/*@
	loop invariant z == 0;
	loop invariant y <= 1000000;
	loop invariant x >= 50000 ==> x == y;
	loop invariant x >= 50000 ==> x % 2 == 0;
	loop invariant x <= y;
	loop invariant x <= 1000000;
	loop invariant x < 50000 ==> y == 50000;
	loop invariant 50000 <= y;
	loop invariant 0 <= x;
	loop assigns y;
	loop assigns x;
	*/
	while(x<1000000){
		if(x<50000)
			x++;
		else{
			x=x+2;
			y=y+2;
		}
	}
	/*@
	loop invariant z == 0;
	loop invariant y <= 1000000;
	loop invariant x == y;
	loop invariant x <= 1000000;
	loop invariant 0 <= y;
	loop invariant 0 <= x;
	loop assigns y;
	loop assigns x;
	*/
	while(y>z){
		y--;
		x--;
	}
	//@assert((x%2==0));
	return 0;
}
