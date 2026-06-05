#include <assert.h>
int unknown1();
int unknown2();
int unknown3();
int unknown4();

void main()
{
  int x = 0;
  int y = 0;
  int i = 0;
  int j = 0;

  while(unknown1())
  {
    /*@
    loop invariant x == y || x < y;
    loop invariant x >= 0;
    loop invariant y >= 0;
    loop invariant i >= 0;
    loop invariant j >= 0;
    loop invariant i >= j;
    loop assigns i, j, x, y;
    */
    while(unknown2())
    {
       if(x == y)
          i++;
       else
          j++;
    }
    if(i >= j)
    {
       x++;
       y++;
    }
    else
       y++;
  }

  // @ assert(i >= j);
}
