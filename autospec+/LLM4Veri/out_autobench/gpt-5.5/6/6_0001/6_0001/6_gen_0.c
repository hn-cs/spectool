int main()
{
   int x = 0;
   int size;
   int y, z;

   /*@
   loop invariant x >= 0;
   loop invariant x == 0 || y <= z;
   loop invariant x == 0 || x <= size;
   loop assigns x, y;
   loop variant size - x;
   */
   while(x < size) {
      x += 1;
      if( z <= y) {
         y = z;
      }
   }

   //post-condition
   if(size > 0) {
      // @ assert(z >= y);
   }
}
