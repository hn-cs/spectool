
void foo(int y, int z)
{
   int x = 0;

   /*@
   loop invariant y <= z;
   loop invariant y <= z || y == 5;
   loop invariant x >= y || y == z;
   loop invariant x == y || x < y;
   loop invariant x <= 5;
   loop invariant 0 <= x;
   loop assigns y;
   loop assigns x;
   */
   while(x < 5) {
      x += 1;
      if( z <= y) {
         y = z;
      }
   }

   //post-condition
   // @ assert(z >= y);
}
