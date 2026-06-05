
void foo(int y, int z)
{
   int x = 0;

   /*@
   loop invariant z <= y;
   loop invariant z < y;
   loop invariant y == z || y <= x;
   loop invariant x == 0;
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
