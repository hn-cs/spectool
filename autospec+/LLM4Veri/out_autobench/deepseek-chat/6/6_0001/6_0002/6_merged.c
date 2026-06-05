int main()
{
   int x = 0;
   int size;
   int y, z;

   /*@
   loop invariant 0 <= x;
   loop assigns y;
   loop assigns x;
   */
   while(x < size) {
      x += 1;
      if( z <= y) {
         y = z;
      }
   }

   //post-condition
   if(size > 0) {
      //@ assert(z >= y);
   }
}
