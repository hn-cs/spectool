int main()
{
   int x = 0;
   int size;
   int y, z;

   /*@
   loop invariant z <= y || y == z;
   loop invariant \forall integer k; 0 <= k < x ==> (z <= y || y == z);
   loop invariant \exists integer k; \old(y) <= k <= z && y == k;
   loop invariant z == \at(z, Pre);
   loop invariant y == \old(y) || y == z;
   loop invariant y <= z;
   loop invariant x == \old(x) + x - x;
   loop invariant x == \at(x, Pre) + (x - \at(x, Pre));
   loop invariant x <= size;
   loop invariant \forall integer k; \old(y) <= k <= z ==> \true;
   loop invariant \at(y, Pre) <= y <= \at(y, Pre) || y == z;
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
