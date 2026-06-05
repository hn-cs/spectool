int main()
{
   int x = 0;
   int size;
   int y, z;

   /*@
   loop invariant x == size ==> z >= y;
   loop invariant x <= size;
   loop invariant x < size;
   loop invariant \forall integer k; 0 <= k < x ==> z >= y;
   loop invariant 0 <= x ==> z >= y;
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
      // @ assert(z >= y);
   }
}
