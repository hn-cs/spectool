int main() {
  int x = -15000;
  int y = 0;
  
  /*@
  loop invariant x == -15000 + (y*(y-1))/2;
  loop invariant 0 <= y;
  loop invariant y <= 173;
  loop invariant x + y == \at(x, Pre);
  loop invariant x < 0;
  loop invariant y == \at(y, Pre) + (1 - \at(y, Pre));
  loop invariant x + (y*(y-1))/2 == -15000;
  loop invariant 0 <= y;
  loop invariant -15000 <= x;
  loop assigns y;
  loop assigns x;
  */
  while (x < 0) {
    x  = x + y;
    y  = y + 1;
  }
  // post-condition
  // @ assert(y > 0);
}
