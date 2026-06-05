#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();

/*@
requires flag > 0;
*/
void foo(int flag, int a) {
   int b;
   int j = 0;
   /*@
   loop invariant (flag == 0) == (j == 0);
   loop invariant (flag == 1) == (j == b);
   loop invariant (flag == 1) ==> b == 100 ==> j == 100;
   loop invariant 0 <= j <= b;
   loop invariant b <= 100;
   loop invariant 0 <= j;
   loop invariant flag == 0 ==> j == 0;
   loop invariant flag != 0 ==> 0 <= j <= b;
   loop invariant b <= 100;
   loop invariant b - j <= 100;
   loop invariant b - j <= 100 || 0 <= b - j;
   loop invariant b - j < 100;
   loop invariant 0 <= b;
   loop invariant 0 <= b - j;
   loop invariant (flag == 1) ==> (j == b);
   loop invariant (flag == 0) ==> (j == 0);
   loop invariant (flag == 0) ==> (b == 100 ==> j == 0);
   loop assigns j;
   loop assigns b;
   */
   for (b = 0; b < 100 ; ++b){
      if (flag)
         j = j + 1;
   }

   if(flag) {
      // @ assert(j==100);
   }
}
