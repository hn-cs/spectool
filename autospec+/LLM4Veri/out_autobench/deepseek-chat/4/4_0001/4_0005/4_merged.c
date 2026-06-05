
void foo(int y, int z)
{
   int x = 0;

   /*@
   loop invariant y <= \at(y, Pre) || y == z;
   loop invariant x == 500 ==> z >= y;
   loop invariant z == \at(z, Pre);
   loop invariant y <= z;
   loop invariant y <= z || x == 0;
   loop invariant x == \at(x, Pre) + ( \at(y, Pre) > z ? (x - \at(x, Pre)) : (x - \at(x, Pre)) );
   loop invariant x <= 500;
   loop invariant x + y - z <= 500;
   loop invariant x + y - z < 500;
   loop invariant \old(y) == y && \old(z) == z;
   loop invariant \old(y) == \old(y);
   loop invariant \at(y, Pre) > z ==> y == \at(y, Pre);
   loop invariant \at(y, Pre) == y || y <= z;
   loop invariant \at(y, Pre) <= z ==> y == z;
   loop invariant 500 - x;
   loop invariant 0 <= x;
   loop assigns y;
   loop assigns x;
   */
   while(x < 500) {
      x += 1;
      if( z <= y) {
         y = z;
      }
   }

   //post-condition
   //@ assert(z >= y);
}
