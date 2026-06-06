typedef int value_type;
typedef unsigned int size_type;

void test(value_type* a, value_type* b, size_type n) {
  //@ admit \base_addr(a) != \base_addr(b);
  return;
}
