int main() {
  int x = -50;
  int y = 0;
  
  /*@
  loop invariant x <= 0;
  loop invariant x + y*(y+1)/2 == -50;
  loop invariant 0 <= y;
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
