int main()
{
  unsigned int i = 0;
  unsigned int j = 0;
  unsigned int k = 0;
  /*@
  loop invariant k == i + j;
  loop invariant k <= 0x0fffffff;
  loop invariant j <= 2*i;
  loop invariant i <= j/2;
  loop invariant 0x0fffffff - k;
  loop invariant 0 <= k;
  loop invariant 0 <= j;
  loop invariant 0 <= i;
  loop assigns k;
  loop assigns j;
  loop assigns i;
  */
  while (k < 0x0fffffff) {
    i = i + 1;
    j = j + 2;
    k = k + 3;
    // @ assert(k == (i + j));
  }
}
