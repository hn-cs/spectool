
void foo(int y, int z)
{
   int x = 0;

   /*@
   loop invariant x == 0 || z >= y;
   loop invariant x <= 500;
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
   // @ assert(z >= y);
}
