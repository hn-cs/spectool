#include <limits.h>
#ifndef __cplusplus
typedef int bool;
#define false ((bool)0)
#define true ((bool)1)
#endif
typedef int value_type;
typedef unsigned int size_type;

int main(void) {
  int a[10];
  int b[10];
  //@ assert \separated(a, b);
  return 0;
}
