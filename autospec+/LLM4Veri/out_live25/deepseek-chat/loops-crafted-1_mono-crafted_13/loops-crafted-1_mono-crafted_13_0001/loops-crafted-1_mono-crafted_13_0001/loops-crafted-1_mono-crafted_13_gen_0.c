int main(){
	int x=0,y=50000,z=0;
	x=0;
	/*@
	loop invariant 0 <= x <= 1000000;
	loop invariant 0 <= y <= 50000;
	loop invariant x >= y;
	loop invariant x % 2 == 0;
	loop invariant (x < 50000) ==> (x == \old(x) + 1);
	loop invariant (x >= 50000) ==> (x == \old(x) + 2 && y == \old(y) + 2);
	loop assigns x, y;
	loop variant 1000000 - x;
	*/
	while(x<1000000){
		if(x<50000)
			x++;
		else{
			x=x+2;
			y=y+2;
		}
	}
	while(y>z){
		y--;
		x--;
	}
	//@assert((x%2==0));
	return 0;
}
