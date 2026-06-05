int main(){
	int x=0,y=50000,z=0;
	x=0;
	/*@
	loop invariant y <= x;
	loop invariant y <= 50000;
	loop invariant x <= 1000000;
	loop invariant x % 2 == 0;
	loop invariant 1000000 - x;
	loop invariant 0 <= y;
	loop invariant 0 <= x;
	loop invariant (x >= 50000) ==> (x == \old(x) + 2 && y == \old(y) + 2);
	loop invariant (x < 50000) ==> (x == \old(x) + 1);
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
	loop invariant z <= y;
	loop invariant x - y == 1000000 - \at(y, Pre);
	loop invariant x % 2 == 0;
	loop invariant 0 <= z;
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
