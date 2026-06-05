int main() {
unsigned int x = 0;
unsigned int y = 10000000;
unsigned int z=0;
	/*@
	loop invariant z == 0 || z % 2 == 0;
	loop invariant z == 0 ==> x <= 5000000;
	loop invariant z % 2 == 0;
	loop invariant x <= y;
	loop invariant 0 <= x;
	loop assigns z;
	loop assigns x;
	*/
	while(x<y){	
		if(x>=5000000)
			z=z+2;
		x++;
	}
  //@assert(!(z%2));
  return 0;
}
