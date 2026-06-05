int unknown1();
int unknown2();

void foo(int flag) {
  int x = 1;
  int y = 1;
  int a;

  if (flag)
    a = 0;
  else
    a = 1;

  /*@
  loop invariant flag == 0 || flag == 1;
  loop invariant a >= x + y || a >= x + y + 1;
  loop invariant 1 <= y;
  loop invariant 1 <= x;
  loop invariant (flag == 1) ==> (a >= x + y + 1);
  loop invariant (flag == 0) ==> (a >= x + y);
  loop assigns y;
  loop assigns x;
  loop assigns a;
  */
  while (unknown1()) {
    if (flag) {
      a = x + y;
      x++;
    } else {
      a = x + y + 1;
      y++;
    }
    if (a % 2 == 1)
      y++;
    else
      x++;
  }
  //x==y

  if (flag)
    a++;
  // @ assert(a % 2 == 1);
}