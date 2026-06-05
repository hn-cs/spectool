#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();


void foo(int flag) {
   int j = 2; 
   int k = 0;

   /*@
   loop invariant flag == 1 ==> k == 0;
   loop invariant flag == 1 ==> j % 4 == 2;
   loop invariant flag == 0 ==> j == 2*k + 2;
   loop invariant flag == 0 ==> j % 2 == 0;
   loop invariant 2 <= j;
   loop invariant flag ==> (j-2) % 4 == 0;
   loop invariant 0 <= k;
   loop invariant !flag ==> k >= 0;
   loop invariant !flag ==> j == 2*k + 2;
   loop invariant !!flag || (j-2) == 2*k;
   loop assigns k;
   loop assigns j;
   */
   while(unknown1()){ 
     if (flag)
       j = j + 4;
     else {
       j = j + 2;
       k = k + 1;
     }
   }
   if(k != 0) {
     //@ assert(j == 2 * k + 2);
   }
}
