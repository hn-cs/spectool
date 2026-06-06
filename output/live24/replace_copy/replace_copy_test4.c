typedef int value_type;
typedef unsigned int size_type;

void test(value_type* a, value_type* b, size_type n) {
  //@ assume \base_addr(a) != \base_addr(b);
  //@ assert 1 == 1;
  return;
}
