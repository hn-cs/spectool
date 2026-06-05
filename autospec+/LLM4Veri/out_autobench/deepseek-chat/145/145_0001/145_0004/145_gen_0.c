int unknown1();
int unknown2();


int main(int flag)
{
  int t = 0;
  int s = 0;
  int a = 0;
  int b = 0;
  /*@
  loop invariant x <= 2 && y <= x + 2;
  loop invariant s <= t;
  loop invariant flag == 0 ==> t == 2*s;
  loop invariant flag != 0 ==> t == 2*s + a;
  loop invariant a == b;
  loop invariant 0 <= y;
  loop invariant 0 <= t;
  loop invariant 0 <= s;
  loop invariant 0 <= b;
  loop invariant 0 <= a;
  loop invariant (x + 3) - y;
  loop assigns y;
  */
  while(unknown1()) {
    a++;
    b++;
    s += a;
    t += b;
    if(flag) {
      t += a;
    }
  } 
  //2s >= t
  int x = 1;
  if(flag) {
    x = t - 2*s + 2;
  }
  //x <= 2
  int y = 0;
  // invariant (x <= 2 && y <= x + 2)
  /*@
  loop invariant y <= x + 2;
  loop invariant x <= 2;
  loop invariant 0 <= y;
  loop invariant y <= 3;
  loop invariant \at(y, Pre) <= y;
  loop invariant \at(x, Here) == x;
  loop invariant y <= x + 2;
  loop invariant x <= 2;
  loop invariant 0 <= y;
  loop assigns y;
  */
  while(y <= x){
    if(unknown2()) 
       y++;
    else 
       y += 2;
  }
  // @ assert(y <= 4);
}

