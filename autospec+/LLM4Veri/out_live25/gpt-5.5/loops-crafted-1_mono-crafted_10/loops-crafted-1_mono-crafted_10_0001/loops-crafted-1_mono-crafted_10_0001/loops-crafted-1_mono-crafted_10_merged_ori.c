int main(void)
{
	unsigned int x = 0;
	unsigned int y = 10000000;
	unsigned int z=5000000;
	/*@
	loop invariant z == (x < 5000000 ? 5000000 : x);
	loop invariant y == 10000000;
	loop invariant y - x;
	loop invariant x <= y;
	loop invariant 0 <= x;
	loop assigns z;
	loop assigns x;
	*/
	while(x<y){	
		if(x>=5000000)
			z++;
		x++;
	}
	// @ assert(z==x);
	return 0;
}
