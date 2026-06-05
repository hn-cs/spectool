int main()
{
  unsigned int x = 0;
  unsigned int y = 0;
  unsigned int z = 0;
  unsigned int w = 0;
  /*@
  loop invariant x <= 0x0fffffff;
  loop invariant \forall integer k; 0 <= k < x ==> y == 0x0fffffff;
  loop invariant \forall integer k; 0 <= k < x ==> \at(z, Pre) == 0x0fffffff;
  loop invariant \forall integer k; 0 <= k < x ==> \at(y, Pre) == 0x0fffffff;
  loop invariant 0 <= x;
  loop assigns z;
  loop assigns y;
  loop assigns x;
  */
  while (x < 0x0fffffff) {
    y = 0;
    /*@
    loop invariant y == x;
    loop invariant 0 <= y;
    loop invariant y <= 0x0fffffff;
    loop invariant z == 0x0fffffff;
    loop invariant \at(z, LoopEntry) == 0;
    loop invariant \forall integer k; 0 <= k < y ==> z == 0x0fffffff;
    loop invariant z <= 0x0fffffff;
    loop invariant y == \at(y, Pre) + (y - \at(y, Pre));
    loop invariant y <= 0x0fffffff;
    loop invariant 0 <= z;
    loop invariant 0 <= y;
    loop assigns z;
    loop assigns y;
    */
    while (y < 0x0fffffff) {
   	z =0;
	/*@
	loop invariant z == \at(z, Pre) + (z - \at(z, Pre));
	loop invariant z == 0x0fffffff;
	loop invariant z <= 0x0fffffff;
	loop invariant \at(z, LoopEntry) == 0;
	loop invariant 0 <= z;
	loop assigns z;
	*/
	while (z <0x0fffffff) {
	  z++;
	}
    	// @ assert(z % 4);
	y++;
    }
    // @ assert(y % 2);
    x++;
  }
  // @ assert(x % 2);
  return 0;
}
