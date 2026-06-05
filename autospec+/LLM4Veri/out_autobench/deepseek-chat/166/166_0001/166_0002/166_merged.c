int unknown1();
int unknown2();
int unknown3();

void foo(int k)
{
  int z = k;
  int x = 0;
  int y = 0;

  while(unknown1())
  {
    int c = 0;
    /*@
    loop invariant y == 0;
    loop invariant x == y;
    loop invariant x == 0;
    loop invariant x + y == 0;
    loop invariant x + c == y + c;;
    loop invariant c == 0;
    loop invariant 0 <= c;
    loop assigns y;
    loop assigns x;
    loop assigns c;
    */
    while(unknown2())
    {
      if(z==k+y-c)
      {
        x++;
        y++;
        c++;
      }else
      {
        x++;
        y--;
        c++;
      }
    }
    /*@
    loop invariant x - y == \old(x) - \old(y);
    loop invariant x + y == \old(x) + \old(y);
    loop invariant 0 <= y;
    loop invariant 0 <= x;
    loop assigns y;
    loop assigns x;
    */
    while(unknown3())
    {
      x--;
      y--;
    }
    z=k+y;
  }
  // @ assert(x==y);
}
