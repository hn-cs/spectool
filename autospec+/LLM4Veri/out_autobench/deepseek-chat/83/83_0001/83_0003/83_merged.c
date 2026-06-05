int main() {
  int x = -5000;
  int y = 0;
  
  /*@
  loop invariant x == -5000 + y*(y-1)/2;
  loop invariant x + y <= 0;
  loop invariant x + y < 0;
  loop invariant x + y < 0;
  loop invariant x + y < 0;
  loop invariant x + y < 0;
  loop invariant x + y < 0;
  loop invariant x + y < 0;
  loop invariant x + y < 0;
  loop invariant x + y < 0;
  loop invariant x + y == \at(x, Pre) + \at(y, Pre);
  loop invariant \at(x, Pre) == -5000;
  loop invariant 0 <= y;
  loop invariant 0 <= x;
  loop invariant 0 <= x + y;
  loop assigns y;
  loop assigns x;
  */
  while ((x < 0)) {
    x  = x + y;
    y  = y + 1;
  }
  // post-condition
  //@ assert(y > 0);
}
