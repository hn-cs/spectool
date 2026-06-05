int main()
{
	unsigned int x = 0;
	unsigned int y = 10000000;
	unsigned int z=5000000;
	/*@
	loop invariant 0 <= x <= y;
	loop invariant z + x >= 5000000;
	loop invariant z <= 5000000;
	loop invariant (x <= 5000000 ==> z == 5000000);
	loop invariant (x > 5000000 ==> z == 5000000 - (x - 5000000));
	loop assigns x, z;
	*/
	while(x<y){	
		if(x>=5000000)
			z--;
		x++;
	}
	// @ assert(z==0);
	return 0;
}
