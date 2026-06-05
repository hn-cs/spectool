int main(void)
{
	unsigned int x = 0;
	unsigned int y = 10000000;
	unsigned int z=5000000;
	/*@
	loop invariant 0 <= x <= y;
	loop invariant y == 10000000;
	loop invariant z == (x < 5000000 ? 5000000 : x);
	loop assigns x, z;
	loop variant y - x;
	*/
	while(x<y){	
		if(x>=5000000)
			z++;
		x++;
	}
	// @ assert(z==x);
	return 0;
}
