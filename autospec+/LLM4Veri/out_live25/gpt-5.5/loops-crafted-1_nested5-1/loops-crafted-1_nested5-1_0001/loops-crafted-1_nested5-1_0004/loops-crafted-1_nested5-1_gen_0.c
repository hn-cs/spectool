int main()
{
  unsigned int x = 0;
  unsigned int y = 0;
  unsigned int z = 0;
  unsigned int w = 0;
  unsigned int v = 0;
  for(w=0;w<0x0fffffff;w++)
  	/*@
  	loop invariant x <= 10;
  	loop invariant y <= 10;
  	loop invariant z <= 10;
  	loop invariant v <= 10;
  	loop assigns x;
  	loop assigns y;
  	loop assigns z;
  	loop assigns v;
  	*/
  	for(x=0;x< 10;x++)
	   /*@
	   loop invariant z <= 10;
	   loop invariant y <= 10;
	   loop invariant v <= 10;
	   loop invariant 10 - y;
	   loop invariant 0 <= y;
	   loop assigns z;
	   loop assigns y;
	   loop assigns v;
	   */
	   for(y=0;y< 10;y++)
		/*@
		loop invariant z <= 10;
		loop invariant v <= 10;
		loop invariant 10 - z;
		loop invariant 0 <= z;
		loop assigns z;
		loop assigns v;
		*/
		for(z=0;z< 10;z++) {
			/*@
			loop invariant v <= 10;
			loop invariant 10 - v;
			loop invariant 0 <= v;
			loop assigns v;
			*/
			for(v=0;v< 10;v++);
			// @ assert(v % 4);
	   }
  return 0;
}
