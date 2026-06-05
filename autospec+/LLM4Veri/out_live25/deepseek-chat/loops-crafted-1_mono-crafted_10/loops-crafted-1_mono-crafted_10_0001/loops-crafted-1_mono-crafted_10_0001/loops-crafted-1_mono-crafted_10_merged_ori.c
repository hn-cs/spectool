int main(void)
{
	unsigned int x = 0;
	unsigned int y = 10000000;
	unsigned int z=5000000;
	/*@
	loop invariant z == 5000000 || z == x;
	loop invariant y - x;
	loop invariant x <= y;
	loop invariant 0 <= x;
	loop invariant (x < 5000000 && z == 5000000) || (x >= 5000000 && z == x);
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
