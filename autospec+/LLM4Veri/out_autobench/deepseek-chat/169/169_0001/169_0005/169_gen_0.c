int unknown1();
int unknown2();
int unknown3();

void foo(int flag) {
  int a = 0;
  int b = 0;
  int x = 0;
  int y = 0;
  int z = 0;
  int j = 0;
  int w = 0;

  /*@
  loop invariant x + y == z + w;
  loop invariant \at(z, Here) == z;
  loop invariant \at(y, Here) == y;
  loop invariant \at(x, Here) == x;
  loop invariant \at(w, Here) == w;
  loop invariant 0 <= z;
  loop invariant 0 <= y;
  loop invariant 0 <= x;
  loop invariant 0 <= w;
  loop assigns z;
  loop assigns y;
  loop assigns x;
  loop assigns w;
  loop assigns k;
  loop assigns j;
  loop assigns i;
  loop assigns b;
  loop assigns a;
  */
  while (unknown1()) {
    int i = z;
    int j = w;
    int k = 0;
    /*@
    loop invariant k == i - z;
    loop invariant k <= j - z;
    loop invariant i == z + k;
    loop invariant i <= j;
    loop invariant j - i == w - z - k;
    loop invariant 0 <= k;
    loop invariant 0 <= j - i;
    loop invariant \at(j, Here) == w;
    loop invariant \at(i, Pre) == z;
    loop assigns k;
    loop invariant k <= j - z;
    loop invariant j - i;
    loop invariant i == z + k;
    loop invariant i - z <= j - z;
    loop invariant \at(j, Pre) == w;
    loop invariant \at(i, Pre) == z;
    loop invariant 0 <= k;
    loop invariant 0 <= i - z;
    loop assigns k;
    loop assigns i;
    */
    while (i < j) {
      k++;
      i++;
    }

    x = z;
    y = k;

    if (x % 2 == 1) {
      x++;
      y--;
    }

    /*@
    loop invariant x + y == z + w;
    loop invariant 0 <= y;
    loop invariant 0 <= x;
    loop assigns y;
    loop assigns x;
    */
    while (unknown2()) {
      if (x % 2 == 0) {
        x += 2;
        y -= 2;
      } else {
        x--;
        y--;
      }
    }
    z++;
    w = x + y + 1;
  }

  int c = 0;
  int d = 0;
  /*@
  loop invariant c == d;
  loop invariant c <= d;
  loop invariant a - b == 0;
  loop invariant \at(a, Pre) == a - (flag ? 1 : c) && \at(b, Pre) == b - (flag ? 1 : d);
  loop invariant 0 <= c;
  loop assigns d;
  loop assigns c;
  loop assigns b;
  loop assigns a;
  */
  while (unknown3()) {
    c++;
    d++;
    if (flag) {
      a++;
      b++;
    } else {
      a += c;
      b += d;
    }
  }
  // @ assert(w >= z && a - b == 0);
}