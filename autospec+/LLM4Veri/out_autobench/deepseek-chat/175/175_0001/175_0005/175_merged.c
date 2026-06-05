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
  loop invariant flag == 1 == > (a == 2*x -1 || a == 2*x);
  loop invariant flag == 0 == > (a == 2*y || a == 2*y +1);
  loop invariant a - x - y == flag ? 0 : 1;
  loop invariant \at(a, Pre) == 0 || \at(a, Pre) == 1;
  loop invariant (x + y) % 2 == 1 && flag == 1 ==> a == x + y;
  loop invariant (x + y) % 2 == 0 && flag == 0 ==> a == x + y + 1;
  loop invariant (flag == 1 ==> x >= y) || (flag == 0 ==> y >= x);
  loop invariant x >= 1 && y >= 1;
  loop invariant x == y;
  loop invariant x == 1 || a == x + y || a == x + y + 1;
  loop invariant x - y == 0;
  loop invariant x - y == 0 || x - y == 1 || x - y == -1;
  loop invariant flag == 1 ? (a == 2*x || a == x + x + 1) : (a == 2*x + 1 || a == x + x + 2);
  loop invariant flag == 1 ? (a == 0 || a == x + y) : (a == 1 || a == x + y + 1);
  loop invariant a == (flag == 1 ? x + y : x + y + 1) || a == (flag == 1 ? x + y + 1 : x + y);
  loop invariant a % 2 == 1 || a % 2 == 0;
  loop invariant \at(y, Pre) == 1;
  loop invariant \at(x, Pre) == 1;
  loop invariant 1 <= y;
  loop invariant 1 <= x;
  loop invariant 0 <= a;
  loop invariant 0 < a;
  loop invariant (flag == 1 ? a == x + y : a == x + y + 1) || (flag == 1 ? a == x + y + 1 : a == x + y);
  loop invariant (a % 2 == 1) == (flag == 0 || (flag == 1 && y % 2 == 1));
  loop invariant (a % 2 == 1 && y >= x) || (a % 2 == 0 && x >= y);
  loop invariant (a % 2 == 1 && (a == x + y || a == x + y + 1)) || (a % 2 == 0 && (a == x + y || a == x + y + 1));
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
  //@ assert(a % 2 == 1);
}